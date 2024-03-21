document.getElementById('investment-form').addEventListener('submit', function(event) {
    event.preventDefault();
    const investmentAmount = parseFloat(document.getElementById('investment-amount').value);

    // Moedas para as quais queremos obter a cotação
    const currencies = ['USD-BRL', 'EUR-BRL', 'BTC-BRL'];

    // URL da API
    const apiUrl = `https://economia.awesomeapi.com.br/json/last/${currencies.join(',')}`;

    // Obter as cotações das moedas
    fetch(apiUrl)
        .then(response => response.json())
        .then(data => {
            const indices = document.getElementById('indices');
            indices.innerHTML = ''; // Limpar os índices anteriores

            for (const currency in data) {
                const rate = parseFloat(data[currency]['bid']);

                const amount = (investmentAmount / rate).toFixed(2);

                const resultBox = document.createElement('div');
                resultBox.classList.add('result-box'); // Adiciona a classe para estilização CSS

                const p = document.createElement('p');
                p.textContent = `Com R$ ${investmentAmount.toFixed(2)} você poderia comprar ${amount} ${currency.split('-')[0]}`;
                resultBox.appendChild(p);

                indices.appendChild(resultBox); // Adiciona a caixa de resultado à div de índices
            }
        })
        .catch(error => {
            console.error("Erro ao obter dados da API:", error);
        });
});
