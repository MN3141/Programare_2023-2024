# !/bin/bash -x

OUTPUT_FILE=paths.txt
st=$PATH
IFS=':' read -ra tokens <<< "$st"
echo > $OUTPUT_FILE
for i in "${tokens[@]}"
do
    echo $i >> $OUTPUT_FILE
done

echo "PATH has been saved" in $(pwd)/$OUTPUT_FILE