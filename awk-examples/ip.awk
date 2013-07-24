BEGIN {
    FS = ".";
}

/^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$/ {
    for (i=1; i<=NF; i++) {
        if ($i>=0 && $i<=255) {
            printf "$Bad ip.\n";
        } else {
            printf "Good ip.\n";
        }
    }
}
