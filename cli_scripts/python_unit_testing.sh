# !/bin/bash -x

#Script for running Python code unit tests and clearing the generated directories 

echo "Starting running unit tests for Python"
cd ../python
pytest
rm -rf .pytest_cache

dir_array=$(ls -d */)
for dir in ${dir_array};
do
    if [ -d "$dir/__pycache__" ]; then
        rm -rf $dir/__pycache__
    fi
done

echo "Done testing for Python"