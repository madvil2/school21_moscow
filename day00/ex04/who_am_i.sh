#!/bin/bash
ldapwhoami -Q | cut -d : -f 2

