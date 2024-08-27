# !/bin/bash -x

#Script for running NodeJS unit tests

echo "Starting running unit tests for NodeJS"
cd ../web

dir_array=$(ls -d */)
for dir in ${dir_array};
do
    cd $dir 
    echo "==============================="
    echo "Curent directory:$dir"
    echo "==============================="

    npm ci #npm clean install
    # --install-links=false
    if [ -d "__test__" ]; then
        npm run test
    fi

    cd ..
done

echo "Done testing for NodeJS"