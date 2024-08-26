# !/bin/bash -x

#Script for running NodeJS unit tests

echo "Starting running unit tests for NodeJS"
cd ../python
pytest
rm -rf .pytest_cache

dir_array=$(find . -type d)
for dir in ${dir_array};
do
    if [ -d "$dir/__pycache__" ]; then
        rm -rf $dir/__pycache__
    fi
done

echo "Done testing for Python"