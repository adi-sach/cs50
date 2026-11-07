let memes = [
    {src: "images/meme1.jpg", name: "Dexter"},
    {src: "images/meme2.jpg", name: "Colplay Couple"},
    {src: "images/meme3.jpg", name: "Jake Paul getting knocked out by Anthony Joshua"}
];

let current = 0;

function updateMeme() {
    document.getElementById("meme").src = memes[current].src;
    document.getElementById("meme-name").innerText = memes[current].name;
}

updateMeme();

function nextMeme() {
    current = (current + 1) % memes.length;
    updateMeme();
}

function prevMeme() {
    current = (current - 1 + memes.length) % memes.length;
    updateMeme();
}
