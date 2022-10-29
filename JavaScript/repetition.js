const repeat = (word, numberOfTimesRepeat) => {
    console.log(word);
    numberOfTimesRepeat -= 1;
    if (numberOfTimesRepeat > 0) {
        repeat(word, numberOfTimesRepeat);
    }
}

repeat('hacktoberfest', 10);