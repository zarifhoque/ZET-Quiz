function Send-Email() {

Param(

[parameter(mandatory=$true)][string]$To,
[parameter(mandatory=$true)][string]$Subject,
[parameter(mandatory=$true)][string]$Body

)

# Get the user credentails

$username = (Get-Content -Path "F:\pass.txt")[0]

$password = (Get-Content -Path "F:\pass.txt")[1] | ConvertTo-SecureString -AsPlainText -Force

# Create hash for email

$email = @{

from = $username

to = $To

subject = $Subject

smtpserver = "smtp.gmail.com"

body = $Body

credential = New-Object System.Management.Automation.PSCredential -ArgumentList $username, $password

usessl = $true

verbose = $true

}

Send-MailMessage @email

}
Send-Email -To "hoq314159265@gmail.com" -Subject "200041147" -Body "Marks:0.000000  Take taken: 9seconds"