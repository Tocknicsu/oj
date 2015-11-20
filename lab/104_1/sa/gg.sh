#!/bin/sh

srand(){
    seed=`awk 'BEGIN{ srand(); print int(rand()*65536); }'`
}
rand(){
	seed=`awk "BEGIN{ srand($seed*2+int(rand()*65536)); print int(rand()*65536)}"`
}

srand
for i in range $(seq 1 10000); do
rand
echo $seed
done
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
rand
echo $seed
