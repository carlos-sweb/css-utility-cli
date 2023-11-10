#! /bin/bash
search_dir=./config
for entry in "$search_dir"/*
do
  NAME="${entry##*/}"
  NAME2="${NAME%.*}"
  FILENAME="${entry%.*}"
  EXTENSION="${entry##*.}"
  if [ "$EXTENSION" = "yml" ];
  then
    xxd -i -n $NAME2"_"$EXTENSION $entry > $FILENAME".h"
  fi

  if [ "$EXTENSION" = "css" ] && [ "$NAME2" = "normalize.min" ];
  then 
    xxd -i -n $NAME2"_"$EXTENSION $entry > $FILENAME".h"
  fi

done