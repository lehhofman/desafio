function marcarResposta(resposta) {

    const respostas = resposta.parentElement.getElementsByClassName('resposta');

    for (let i = 0; i < respostas.length; i++) {

        respostas[i].classList.remove('selecionada');

    }

    resposta.classList.add('selecionada');

}

function validarRespostas() {

    const gabarito = {
        
        1: 'A',
        2: 'C',
        3: 'B',
        4: 'D',
        5: 'D',
        6: 'E',
        7: 'A',
        8: 'C',
        9: 'B',
        10: 'D'

    };

    let acertos = 0;
    let erros = 0;

    for (let i = 1; i <= 10; i++) {

        const respostas = document.getElementById('respostas' + i).getElementsByClassName('resposta');
        let respostaAluno = '';

        for (let j = 0; j < respostas.length; j++) {

            if (respostas[j].classList.contains('selecionada')) {

                respostaAluno = respostas[j].innerText;
                break;

            }

        }

        const respostaCorreta = gabarito[i];

        if (respostaAluno === respostaCorreta) {

            acertos++;

        } else {

            erros++;

        }
        
    }

    const resultado = document.getElementById('resultado');
    resultado.innerHTML = `Acertos: ${acertos}, Erros: ${erros}`;
}
