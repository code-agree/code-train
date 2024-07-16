#!/bin/bash

set -e

job_id="zte.wireless.ccn.ccsp.productci.smf.build"
new_result="failed"

yq w -i -- "$1" metadata.jobs."$job_id".result "$new_result"