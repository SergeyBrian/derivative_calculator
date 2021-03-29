//
// Created by sergio on 27.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_RENDERER_H
#define DERIVATIVE_CALCULATOR_RENDERER_H

#include <string>
#include <fstream>

using namespace std;

class Renderer {
private:
    string filename, source, result;
public:

    /*!
     * Render html page with results
     * @return 0 - success
     * 1 - Cannot open file
     */
    int Render(const string& name, const string& src, const string& res) {
        filename=name, source=src, result=res;
        ofstream output(filename);
        if (!output) return 1;
        output << "<!DOCTYPE html><html lang='ru'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><link rel='stylesheet' href='https://cdn.jsdelivr.net/npm/katex@0.13.0/dist/katex.min.css' integrity='sha384-t5CR+zwDAROtph0PXGte6ia8heboACF9R5l/DiY+WZ3P2lxNgvJkQk5n7GPvLMYw' crossorigin='anonymous'> <script src='https://cdn.jsdelivr.net/npm/katex@0.13.0/dist/katex.min.js' integrity='sha384-FaFLTlohFghEIZkw6VGwmf9ISTubWAVYW8tG8+w2LAIftJEULZABrF9PPFv+tVkH' crossorigin='anonymous'></script> <script src='https://cdn.jsdelivr.net/npm/katex@0.13.0/dist/contrib/auto-render.min.js' integrity='sha384-bHBqxz8fokvgoJ/sc17HODNxa42TlaEhB+w8ZJXTc2nZf1VgEaFZeZvT4Mznfz0v' crossorigin='anonymous' onload='renderMathInElement(document.body);'></script> <title>Результат</title></head><body> <section><h1>Результат поиска производной</h1><h2>Исходная функция</h2><div id='source'></div><h2>Функция производной</h2><div id='result'></div> </section></body><style>body{margin:0;padding:0}section{background-color:#ccc;margin:1%}h1{font-size:2em;padding:1%;text-align:center}h2{padding:1%}div{padding:3%}</style> <script>katex.render('";
        output << source;
        output << "',document.getElementById('source')); katex.render('";
        output << result;
        output << "',document.getElementById('result'))</script> </html>";
        return 0;
    }
};


#endif //DERIVATIVE_CALCULATOR_RENDERER_H
