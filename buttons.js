document.addEventListener("DOMContentLoaded", function () {
    // Get the button element by its ID
    var button1 = document.getElementById('button00');
    const buttons = document.querySelectorAll('.connections-button');
    var selectedButtons = [];
    var buttonsText = [];

    buttons.forEach(function (button) {
        button.addEventListener('click', function () {
            button.classList.toggle('active');

            var isActive = button.classList.contains('active');

            if (isActive) {
                selectedButtons.push(button);
                buttonsText.push(button.textContent)

                if (selectedButtons.length === 4) {
                    selectedButtons.forEach(function (button) {
                        button.classList.remove('active');
                    });
                    var buttonTexts = selectedButtons.map(function(button) {
                        return button.textContent;
                    });
                    var arrayString = buttonTexts.join('\n');
                    function checkButtons() {
                        var xhr = new XMLHttpRequest();
                        xhr.onreadystatechange = function() {
                            if (xhr.readyState === XMLHttpRequest.DONE) {
                                if (xhr.status === 200) {
                                    // Update HTML with response
                                    document.getElementById("network-response").textContent = xhr.responseText;
                                } else {
                                    console.error('Request failed: ' + xhr.status);
                                }
                            }
                        };
                        xhr.open("POST", "checker.php", true);
                        xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
                        xhr.send("arrayString=" + encodeURIComponent(arrayString)); // Send text to server
                    }
                    checkButtons();
                    selectedButtons = [];
                }
            }

            if (!isActive) {
                var index = selectedButtons.indexOf(button);
                selectedButtons.splice(index, 1);
                buttonsText.splice(index, 1);
            }
        });
    });
});
