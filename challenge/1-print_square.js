#!/usr/bin/node

// Check if an argument was provided
if (process.argv.length < 3) {
    process.stderr.write("Missing argument\n");
    process.exit(1);
}

// Parse the size from the command line argument (base 10)
const size = parseInt(process.argv[2], 10);

// Check if size is a valid number
if (isNaN(size)) {
    process.stderr.write("Argument must be a number\n");
    process.exit(1);
}

// Loop to print the square
for (let i = 0; i < size; i++) {
    for (let j = 0; j < size; j++) {
        process.stdout.write("#");
    }
    // FIX: Print a newline after completing each row
    process.stdout.write("\n");
}
