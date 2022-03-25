#! /bin/bash

NEW_LOG=$(date +%Y%m%d_%H%M%S).log
OLD_LOG="19920104_091532.log"

./tests > $NEW_LOG

#  remove timestamp
cat $NEW_LOG | awk '{ print $2 }' > new.log;
cat $OLD_LOG | awk '{ print $2 }' > old.log;

# execute diff command and save the result.
diff --normal new.log old.log | tee result.txt;

# cleanup
rm $NEW_LOG new.log old.log
