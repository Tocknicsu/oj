#!/bin/sh
unit=c
help(){
	echo "./weather -l locations [-u unit] [-a | -c | -d day | -s]"
}
. ~/.weather.conf
while getopts "hl:u:acd:s" OPTION; do
	case $OPTION in
		h) help;;
		l) location=$OPTARG;;
		u) unit=$OPTARG;;
		a) current_condition=1;days=5;sunset=1;;
		c) current_condition=1;;
		d) days=$OPTARG;;
		s) sunset=1;;
	esac
done
if [ -z $location ]; then
	echo "Must specify location"
	help; exit
fi
if [ -n "$current_condition" -o -n "$days" -o -n "$sunset" ] ; then
else
	echo "Must specify type of information"
	help; exit
fi
IFS=","
for locat in $location; do
	woeid=`curl -s "http://where.yahooapis.com/v1/places.q('$locat');start=0;count=1?appid=dj0yJmk9cktwMDdZNFFXSjVvJmQ9WVdrOVZ6aENOVWxqTTJNbWNHbzlNQS0tJnM9Y29uc3VtZXJzZWNyZXQmeD1mZQ--" | sed -e 1,1d -e "s/.*<locality1//g" -e "s/>.*//g" -e "s/.*woeid=//g" -e "s/\"//g"`
	content=`curl -s "http://weather.yahooapis.com/forecastrss?w=$woeid&u=$unit"`
	if [ $current_condition ] ; then
		city=`echo $content | grep yweather:location | sed -e "s/.*city=\"//g" -e "s/\".*//g"`
		now=`echo $content | grep yweather:condition`
		text=`echo $now | sed -e "s/.*text=\"//g" -e "s/\".*//g"`
		temp=`echo $now | sed -e "s/.*temp=\"//g" -e "s/\".*//g"`
		printf "%s, %s, %s°%s\n" $city $text $temp $unit
	fi
	if [ $days ] ; then
		data=`echo \$content | grep yweather:forecast | head -n $days`
		IFS=$'\n'
		for now in $data; do
			date=`echo $now | sed -e "s/.*date=\"//g" -e "s/\".*//g"`
			day=`echo $now | sed -e "s/.*day=\"//g" -e "s/\".*//g"`
			low=`echo $now | sed -e "s/.*low=\"//g" -e "s/\".*//g"`
			high=`echo $now | sed -e "s/.*high=\"//g" -e "s/\".*//g"`
			text=`echo $now | sed -e "s/.*text=\"//g" -e "s/\".*//g"`
			printf "%s %s %s°%s ~ %s°%s %s\n" $date $day $low $unit $high $unit $text
		done
		IFS=","
	fi
	if [ $sunset ] ; then
		now=`echo $content | grep yweather:astronomy`
		sunrise=`echo $now | sed -e "s/.*sunrise=\"//g" -e "s/\".*//g"`
		sunset=`echo $now | sed -e "s/.*sunset=\"//g" -e "s/\".*//g"`
		printf "sunrise: %s, sunset: %s\n" $sunrise $sunset
	fi
done
