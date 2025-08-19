# create a virtual environment
```
python3 -m venv pdf
source pdf/bin/activate
```


#### pyperclipe

deals with strings in the clippbord
.copy("string")
.past()
#### pprint module
to pretty print dictionary

#### Dictionary 
get("key","default return") -> if a key doesn't exist return a default value
setdefault("key","default value") -> if a key doesn't exist create it with a default value

##### Strings

.isupper()
.islower()
.upper()
.lower()
.istitle()
.isalnum()
.isspace()
.isdecimal()
.startswith()
.endswith()
.find("string") -> return index
'delemeter'.join(\[list of strings\]) -> join list of strings sparated with a delemter
"string".split() -> string to list
.ljust(int,"optional fill") -> justify to right (add white spaces)
.rjust(int,"optional fill") ->  justify to left (add white spaces)
.center(int,"optional fill")
.strip() -> remove white space from both sides
.rstrip() -> remove white space from right 
.lstrip() -> remove white space from left
.replace("x","y") -> replace x by y

###### string formatting

"hello %s you are late it is \%s" % (name , time)

##### Run using  shebang
#!/bin/python


##### Regular expressions 

module -> re 
obj = re.compile(r'expression') -> create regular expression object
obj.search("string") ->  return an re match object string
obj.search("string").group() -> return a string match the pattern
obj.findall("string") -> return list of hit expressions or return list of tuple of groups in the regular expression
(string){int} -> match the expression exactly int times
(string){min,max} -> match the expression min and max times
\d -> numeric digit
\D -> any character that is not a numeric
\w -> letter or number or _ (word)
\W -> nay thing not letter or number or _ 
\s -> space or newline or tab
\S -> any thing except space or newline or tab
\[aeoui\] = (a | e | o | u | i)
\[0-9\] -> from 0 to 9
\+ -> one or more 
? -> zero or one
\* -> zero or more 
. -> one character except newline
\[^aeoui\] = any thing not (a | e | o | u | i)
re.compile(r'.\*' , re.DOTALL) -> include newlines
re.compile(r'\[aeoui\]',re.I) -> ignorecase 
.sub("string" | \1, "match string") -> subtitute string in match string, \1 means first group
re.compile(r'''  string  ''',re.VERBOSE) -> ignore white spaces in the expression

##### OS
os.path.join("str1","str2","str3") -> join strings to create a path that appropriate for the used os

os.sep -> contain the folder separator of the os 
os.getcwd()  -> get the current working directory
os.chdir("path") -> change directory
os.path.abspath("path") -> return an absolute path of the path you pass it 
os.path.relpath("path") -> return an relative path of the path you pass it 
os.path.isabs("path") -> return bool if the path is absolute
os.path.dirname("path") -> get the first part of the path
os.path.basename("path") -> get the last part of the path
os.path.exists("path") -> check if a path exists
os.path.isfile("path")
os.path.isdir("path")
os.path.getsize("path")
dir  = os.path.listdir("path") -> return a list of the content
dir.endswith("extention") -> check if a file name ends with string
os.makedirs("path")
os.unlink(file) -> delete a file
os.rmdir(dir) -> delete an empty dir
os.walk() -> return list of ( dir name , list of all dirs, list of all files of dir ) 


##### Files
var = open("path",option) -> if doesn't exit it creates it
- options : 
	- 'w'  -> overwrite
	- 'a'  -> append
var.close()
var.read() -> return a string of the content
var.readlines() -> return list of lines 
var.write("string")


###### shelve module
- deals with structured data
file = shelve.open("file name) -> create a db file if not exist
file\[key\] = \["val1","val2","val3"]
.keys()
.values()

###### shutil

shutil.copy("src","dest") -> copy src file to dest file , can change name in dest too
.copytree(src,dest) -> copy directory src to dest
.move(src,dest) -> cut and past, can rename too
.rmtree(dir) -> delete dir with it's content


###### send2trash

send2trash.send2trash(path)
send2trash.


##### error handle
- raise
- assert from module assert

##### sys module

sys.argv -> list of arguments
##### webscraping

###### webbrowser module
.open(url) -> open a url in browser

###### requests module
res = requests.get(url) -> download a file
res.status_code  -> variable contain the status code
res.raise_for_status() -> raise exception
res.iter_content(size) -> return amount of data with size
res.text

##### bs4 module (beautiful soup)

soup = bs4.BeautifulSoup(res.text, 'html.parser')
soup.select('css selector') -> return a specified html element



##### excel word and pdf manipulation

###### openpyxl module 

wo = openpyxl.load_workbook("path to .xlsx")
sheet = wo.get_sheet_by_name("sheet name")
sheet.title(new sheet name)
wo.get_sheet_names()
cell = sheet\[A1]
str(cell.value())
sheet.cell(row= rownum , column = colnum)
wo.save("file name")
wo.create_sheet(index, title)


###### PyPDF2 module
extract text 


fd = open(file,rb)
pdf = PyPDF2.PdfReader(fd)
pdf.pages
page = pdf.pages\[index\] -> index starts from 0
page.extract_text()

writer = PyPDF2.PdfFileWrite() -> create a new empty pdf 
writer.addPage()
out = open(file.pdf,wb)
writer.write(out)


###### docx moduls

d = doc.Document(file)
d.paragraphs -> contain paragraph objects 
p = d.paragraphs\[0\]
p.text
p.runs\[0].text -> run is created when there is a change in text style
p.runs\[0].bold -> change the style to bold value = true or none
p.runs\[0].italic
p.runs\[0].underline
p.style = \[Title | ...etc]
d.add_paragraph("text")
p.add_run(text)
d.save()



##### Sending Mails
###### smtplib module

conn = smtplib.SMTP('smtp.gmail.com',587)
conn.ehlo()  -> send hello to the smtp server to start the connection
conn.starttls() -> start tls encryption to send username and password
conn.login(email,password)
conn.sendmail(from address , to address, body)

- body format
	- "Subject: subject \n\nDear al,\n so lon, ...... "
conn.quit()