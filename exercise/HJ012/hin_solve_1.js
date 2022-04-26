let line;
while (line = readline()) {
    let outline = '';
    for(let i = line.length - 1; i >= 0; i--){
        outline += line[i];
    }
    print(outline);
}
