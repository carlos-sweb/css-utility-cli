#! /bin/bash
for entry in ./config/*
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

for entrada in ./config/property/yml/*
do
  P="${entrada%/*}"
  NAME="${entrada##*/}"
  NAME2="${NAME%.*}"
  FILENAME="${entrada%.*}"
  EXTENSION="${entrada##*.}"
  if [ "${EXTENSION}" = "yml" ];
  then
    xxd -i -n "${NAME2}_${EXTENSION}" "${entrada}" > $P"/../h/"$NAME2".h"
  fi
done