#!/usr/bin/env python3


import json
import os
import sys
import mordor_log

def json_check():

    json_input = ""
    if "" == json_input :
        log("INFO", "Input Json File")
        log("INFO", "./json_checker.py")
        sys.exit(1)

    
    rootpath = os.path.abspath("../")

    with open(json_input) as jf:
        json_info = json.load(jf)

    

    for items in json_info["TEST_CASES"]:
        result = items.get("RESULT")

        if ( None != result):
            # Do Something here
        else:
            log("ERROR", "key is not present")
            error_items = 1
    


    # The items will be sorted 

    if error_items == 1 : sys.exit(1)
    result = []
    result_idx.sort()

    with open(json_input + ".sorted.json", "w") as jf:
        json.dump(results_idx)

    log("INFO", "ALL DONE")



if __name__ == '__main__' : 
    check_json()

