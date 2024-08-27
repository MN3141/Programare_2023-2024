# !/bin/bash -x

#Script for running NodeJS unit tests

echo "Starting running unit tests for NodeJS"
cd ../web

NPM_PATH=$(which npm)
echo $NPM_PATH

dir_array=$(ls -d */)
for dir in ${dir_array};
do
    npm ci --install-links=false #npm clean install

    echo "======================="
    echo $dir
    echo "======================="

    if [ -d "$dir/__test__" ]; then
        npm run test
    fi
done

echo "Done testing for NodeJS"