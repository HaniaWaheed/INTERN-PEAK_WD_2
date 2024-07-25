const quizData = [
    {
        question: "What is the capital of France?",
        a: "Berlin",
        b: "Madrid",
        c: "Paris",
        d: "Lisbon",
        correct: "c",
        image: "images/paris.jpg"
    },
    {
        question: "Who is the CEO of Tesla?",
        a: "Jeff Bezos",
        b: "Elon Musk",
        c: "Bill Gates",
        d: "Tony Stark",
        correct: "b",
        image: "images/elon_musk.jpg"
    },
    {
        question: "What is the most used programming language in 2023?",
        a: "Java",
        b: "C",
        c: "Python",
        d: "JavaScript",
        correct: "c",
        image: "images/python.jpg"
    },
    {
        question: "What does HTML stand for?",
        a: "Hypertext Markup Language",
        b: "Hypertext Markdown Language",
        c: "Hyperloop Machine Language",
        d: "Helicopters Terminals Motorboats Lamborghinis",
        correct: "a",
        image: "images/html.jpg"
    },
    {
        question: "What year was JavaScript launched?",
        a: "1996",
        b: "1995",
        c: "1994",
        d: "None of the above",
        correct: "b",
        image: "images/javascript.jpg"
    }
];

const quiz = document.getElementById('quiz');
const results = document.getElementById('results');
const submitButton = document.getElementById('submit');

let currentQuestionIndex = 0;
let score = 0;

function loadQuiz() {
    const currentQuizData = quizData[currentQuestionIndex];
    quiz.innerHTML = `
        <div class="quiz-question">
            <h2>${currentQuizData.question}</h2>
            <img src="${currentQuizData.image}" alt="Question Image">
            <label>
                <input type="radio" name="answer" value="a">
                ${currentQuizData.a}
            </label>
            <label>
                <input type="radio" name="answer" value="b">
                ${currentQuizData.b}
            </label>
            <label>
                <input type="radio" name="answer" value="c">
                ${currentQuizData.c}
            </label>
            <label>
                <input type="radio" name="answer" value="d">
                ${currentQuizData.d}
            </label>
        </div>
    `;
}

function getSelected() {
    const answerEls = document.querySelectorAll('input[name="answer"]');
    let answer;
    answerEls.forEach(answerEl => {
        if (answerEl.checked) {
            answer = answerEl.value;
        }
    });
    return answer;
}

function showFeedback(isCorrect) {
    const feedback = document.createElement('div');
    feedback.className = isCorrect ? 'correct' : 'incorrect';
    feedback.innerText = isCorrect ? 'Correct!' : 'Wrong!';
    quiz.appendChild(feedback);
    setTimeout(() => {
        quiz.removeChild(feedback);
    }, 1000);
}

submitButton.addEventListener('click', () => {
    const answer = getSelected();
    if (answer) {
        if (answer === quizData[currentQuestionIndex].correct) {
            score++;
            showFeedback(true);
        } else {
            showFeedback(false);
        }
        currentQuestionIndex++;
        if (currentQuestionIndex < quizData.length) {
            setTimeout(loadQuiz, 1000);
        } else {
            quiz.innerHTML = '';
            results.innerHTML = `
                <h2>You answered correctly at ${score}/${quizData.length} questions.</h2>
            `;
        }
    }
});

loadQuiz();
