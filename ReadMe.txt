Project Overview:
The Leakage Detection System in Water Pipelines is designed to address water management challenges and reduce non-revenue water. The system enables real-time monitoring and prompt detection of leaks in water pipelines. This Read Me file provides essential details and instructions for running the project.

Web Part (Laravel):
Make sure you have PHP and Laravel (version 10.13.0) installed on your machine.
Navigate to the "web" directory.
Run the following commands to install dependencies and set up the environment:
composer install
cp .env.example .env
php artisan key:generate
Configure the database settings in the .env file.
Run the migrations: php artisan migrate
Start the Laravel development server: php artisan serve
Open your browser and access the application at http://localhost:8000 or the specified URL.

NodeMCU (Arduino):
Make sure you have the Arduino IDE installed on your machine.
Connect the NodeMCU ESP8266 board to your computer.
Open the Arduino IDE and navigate to the "nodemcu" directory.
Install the required libraries, if any, by going to "Sketch" > "Include Library" > "Manage Libraries".
Select the correct board and port from the Tools menu.
Upload the Arduino sketch to the NodeMCU board by clicking the "Upload" button.

SMS API (Africa's Talking):
Make sure you have an active Africa's Talking account with SMS functionality.
Open the AfricasTalking folder.
Configure the necessary API credentials in the appropriate configuration files.
Make sure the project is connected to the internet to send SMS notifications.

Project Structure:
The "web" directory contains the Laravel web application files.
The "nodemcu" directory contains the Arduino sketch for the NodeMCU ESP8266 board.
The "africastalking" directory contains the SMS API integration files.

Documentation:
Refer to the documentation files provided in the drive for detailed instructions on system usage, configuration, and troubleshooting.

Contact Information:
For any questions or assistance, please contact Rahma, 0766025562.