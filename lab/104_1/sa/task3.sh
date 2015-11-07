#!/bin/sh
INPUT=/tmp/menu.sh
OUTPUT=/tmp/output.sh

#trap "rm $OUTPUT; rm $INPUT; exit" SIGINT SIGTERM

Welcome(){
    dialog --no-collapse --ok-label "Play a Game" --clear --msgbox '
   _________    __  _________
  / ____/   |  /  |/  / ____/
 / / __/ /| | / /|_/ / __/   
/ /_/ / ___ |/ /  / / /___   
\____/_/  |_/_/  /_/_____/   
   ___   ____  __ __  ____ 
  |__ \ / __ \/ // / ( __ )
  __/ // / / / // /_/ __  |
 / __// /_/ /__  __/ /_/ / 
/____/\____/  /_/  \____/  
' 15 34
}
congratulations(){
    dialog --clear --msgbox "
                                _         _       _   _                 \n
                                | |       | |     | | (_)                \n
  ___ ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___ \n
 / __/ _ \\| '_ \ / _\` | '__/ _\` | __| | | | |/ _\` | __| |/ _ \\| '_ \\/ __|\n
| (_| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\\n
 \\___\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___/\n
                  __/ |                                                  \n
                 |___/                                                   \n
" 15 80
}
lose(){
    dialog --ok-label "Play a Game" --clear --msgbox "lose" 15 80
}
win(){
    for i in $(seq 1 4); do
        for j in $(seq 1 4); do
            eval now=\$array$i$j
            if [ $now -eq 64 ]; then
                _game_status=1
            fi
        done
    done
}
draw(){
    
    line1="+-----+-----+-----+-----+\n"
    line2='|     |     |     |     |\n'
    msg=""
    for i in $(seq 1 4); do
        msg=$msg$line1
        msg=$msg$line2
        for j in $(seq 1 4); do
            eval val=\$array$i$j
            if [ $val -eq 0 ]; then
                append='     '
            else
                append=`printf ' %3d ' $val`
            fi
            msg=$msg"|"$append
        done
        msg=$msg"|\n"
        msg=$msg$line2
    done
    msg=$msg$line1
    dialog --no-collapse --no-lines --infobox "$msg" 19 29

}
srand(){
    seed=`awk 'BEGIN{ srand(); print int(rand()*65536); }'`
}
rand(){
    seed=`awk "BEGIN{ srand($seed); print int(rand()*65536)}"`
}
empty(){
    _empty=0
    for i in $(seq 1 4); do
        for j in $(seq 1 4); do
            eval now=\$array$i$j
            if [ $now -eq 0 ]; then
                eval _empty_x$_empty=$i
                eval _empty_y$_empty=$j
                _empty=$(($_empty+1))
            fi
        done
    done
}
random(){
    empty
    if [ $_empty -eq 0 ]; then
        _game_status=-1
        return
    fi
    rand
    pos=$((${seed}%${_empty}))
    rand
    v=$(((${seed}%2+1)*2))
    eval eval array\$_empty_x${pos}\$_empty_y${pos}=$v
}
swap(){
    eval tmp=\$$1
    eval $1=\$$2
    eval $2=\$tmp
}
rotate(){
    for k in $(seq 1 $1); do
        for i in $(seq 1 4); do
            for j in $(seq 1 $i); do
                eval swap array$i$j array$j$i
            done
        done
        for i in $(seq 1 2); do
            for j in $(seq 1 4); do
                eval swap array$i$j array$((4-$i+1))$j
            done
        done
    done
}
move(){
    for k in $(seq 1 4); do
        for i in $(seq 1 4); do
            for j in $(seq 1 3); do
                eval now=\$array$i$j
                eval next=\$array$i$(($j+1))
                if [ $next -eq 0 ]; then continue; fi
                if [ $now -eq 0 ]; then
                    eval swap array$i$j array$i$(($j+1))
                    _new=1
                fi
            done
        done
    done
}
compress(){
    for i in $(seq 1 4); do
        for j in $(seq 1 3); do
            eval now=\$array$i$j
            if [ $now -eq 0 ]; then continue; fi
            eval next=\$array$i$(($j+1))
            if [ $now -eq $next ]; then
                _new=1
                eval array$i$j=\$\(\(\$array$i$j*2\)\)
                eval array$i$(($j+1))=0
            fi
        done
    done
}
init(){
    _game_status=0
    for i in $(seq 1 4); do
        for j in $(seq 1 4); do
            eval array${i}${j}=0
        done
    done
    random
    random
}
save(){
    #dialog --clear --fselect "" 15 80 2>".2048.save.config"
    #read filename < ".2048.save.config"
    filename=`awk 'BEGIN{print ".2048.save." strftime("%Y-%m-%d_%H:%M:%S")}'`
    echo $_game_status > $filename
    for i in $(seq 1 4); do
        for j in $(seq 1 4); do
            eval echo \$array$i$j >> $filename
        done
    done
    dialog --clear --msgbox "Save game at $filename" 6 40
}
load(){
    dialog --clear --fselect "" 15 80 2>".2048.load.config"
    read filename < ".2048.load.config"
    exec 3< $filename
    read _game_status <&3
    for i in $(seq 1 4); do
        for j in $(seq 1 4); do
            eval read array$i$j <&3
        done
    done
    dialog --clear --msgbox "Load $filename" 6 40
}
game(){
    while true; do
        if [ $_game_status -ne 0 ]; then return; fi
        draw
        oldstty=`stty -g`
        stty -icanon -echo min 1 time 0
        key=`dd bs=1 count=1 2>/dev/null` 
        stty "$oldstty"
        case $key in
            w) dir=1;;
            d) dir=2;;
            s) dir=3;;
            a) dir=0;;
            q) break;;
            *) dir=-1;;
        esac
        _new=0
        if [ $dir -ne -1 ]; then
            rotate $dir; move; compress; move; rotate $((4-$dir))
        fi
        if [ $_new -eq 1 ]; then random; fi
        win
    done
}
newgame(){
    init
    game
}
main_menu(){
    dialog \
    --title "menu" \
    --menu "Command Line 2048" 15 50 5 \
    N "New Game - Start a new 2048 game" \
    R "Resume - Resume previous game" \
    S "Save" \
    L "Load" \
    Q "Quit" 2>"${INPUT}"
    read menuitem < "${INPUT}"
    case $menuitem in
        N) newgame;;
        R) game;;
        S) save;;
        L) load;;
        Q) break;;
    esac
    if [ $_game_status -eq 1 ]; then
        congratulations
    elif [ $_game_status -eq -1 ]; then
        lose
    fi
     
}
init
srand
Welcome
while true; do
    main_menu
done
#[ -f $OUTPUT ] && rm $OUTPUT
#[ -f $INPUT ] && rm $INPUT
