for (let i = 1; i <= 100; i++) {
    let temp = i;
    let reversed = 0;

    // Mathematical reverse logic
    while (temp > 0) {
        const digit = temp % 10;
        reversed = (reversed * 10) + digit;
        temp = Math.floor(temp / 10);
    }

    if (i === reversed) {
        console.log(i);
    }
}
