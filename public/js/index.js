async function submit() {
    const n1 = parseInt(document.getElementById("in1").value);
    const n2 = parseInt(document.getElementById("in2").value);
    const n3 = parseInt(document.getElementById("in3").value);
    const n4 = parseInt(document.getElementById("in4").value);
    const n5 = parseInt(document.getElementById("in5").value);
    if (!n1 || !n2 || !n3 || !n4 || !n5) {
        console.log("Invalid args")
        return;
    }
    const response = await fetch('/calc', {
        method: 'POST',
        body: JSON.stringify({n1, n2, n3, n4, n5}),
        headers: {
            'Content-Type': 'application/json'
        }
    });
    const resJson = await response.json();
    const answers = resJson.svar;
    console.log(answers);
    const answerGrid = document.getElementById("answers");
    for(let i = 0; i<answers.length; i++) {
        const answer = document.createElement("div")
        answer.classList.add("answer");

        const num = document.createElement("h3");
        num.innerText = i+1;
        num.classList.add("answer-num");
        answer.appendChild(num)

        const value = document.createElement("h3");
        value.innerText = answers[i];
        value.classList.add("answer-value");
        answer.appendChild(value);


        answerGrid.appendChild(answer);
    }
    answerGrid.classList.remove("hidden");
}
