# !/bin/bash -x

#Script for running NodeJS unit tests

echo "Starting running unit tests for NodeJS"
cd ../web

dir_array=$(find . -type d)
for dir in ${dir_array};
do
    npm ci #npm clean install

    echo "======================="
    echo $dir
    echo "======================="
    
    if [ -d "$dir/__test__" ]; then
        npm run test
    fi
done

echo "Done testing for NodeJS"