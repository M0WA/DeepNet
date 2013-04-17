#!/bin/bash

BASE_DIR="deepnet_tmp/DeepNet"
REPOSITORY="https://svn.siridia.de/DeepNet"
MOVIE_NAME="movie.mpg"

rm -rf ${BASE_DIR}
mkdir-p ${BASE_DIR}
svn co ${REPOSITORY} ${BASE_DIR}/..
svn log --xml --verbose ${BASE_DIR} > ${BASE_DIR}/out.tmp
gource -640x480 --title "evolution of a search engine" --hide "date,users,usernames" --camera-mode overview --max-user-speed 9999 -s 1 -r 25 --auto-skip-seconds 0.1 -o ${BASE_DIR}/out.ppm ${BASE_DIR}/out.tmp
rm -f ${BASE_DIR}/out.tmp
convert -delay 6 -quality 95 ${BASE_DIR}/out.ppm ${BASE_DIR}/${MOVIE_NAME}
rm -f ${BASE_DIR}/out.ppm