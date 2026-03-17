
## Commands

``` bash
django-admin  startproject <project name>  -> create a project
manage.py ruserver <port number> -> specify the port number to run the server 
manage.py startapp <app name>
```


## Project hierarchy

```
| proj-name
| | projname
| | | __init__.py -> empty file tells python to treat the directory as package
| | | asgi.py
| | | settings.py -> configurations for the django project
| | | urls.py  -> contains the urls in the project
| | | wsgi.py
| | manage.py  -> pass commands to the project
```


## Apps

#### Hierarchy
```
| app-name
| | migrations
| | | __init__py
| | __init__.py
| | admin.py
| | apps.py
| | models.py
| | tests.py
| | views.py 		
```

## URLs and Views
- **URL** :is the url you write in the browser
- **View**: handle request and return a response so it contains the logic executed before returning the response.
- **Types**: 
	- Function Based View (FBW)
	- Class Based View (CBV)
##### Add a View
 1. go to views in the app
 2. import : from django.http import HttpResponse
 3. create function : def index(request): 
	    return HttpResponse("Hello world")
 4. go to urls.py in the app the add the urls like this :
	 import the libraries :  from django.urls import path
                           from . import views
   add the url to the function : urlpatterns = \[ path('', views.index, name="index"),]

##### Dynamic URL
- Is a URL that contains **variable parts**. These parts are captured from the URL and passed to the view function as parameters and allows one view to handle many URLs by using values embedded in the path.

``` python
# In urls
# <int:..>  called path converter
urlpatterns = [
	path('board/<int:id>',views.helloworld),
	path('notboard/<int:id>',views.helloworld),
	path('vv',views.vv),
]

# In views
def helloworld(request,id):
	return HttpResponse(f"<h1> {dictionaryy[id]['topic']} </h1> \n {dictionaryy[id]['Content']}")
```


##### HttpResponse methods
```python
from django.http import HttpResponseNotFound
return HttpResponseNotFound("Page doesn't exist")
```
##### Redirection
```python
# in views
from django.http import HttpResponseRedirect
def vview(request):
	return HttpResponseRedirect("/home/hello")

```
##### Reverse Function
``` python
# in urls
urlpatterns = [
path('board/<int:id>',views.helloworld, name= "post"),
]

# in views
from django.urls import reverse
def vview(request, id):
	url = reverse("post",args=[id])
	return HttpResponseRedirect(url)

```


## Templates
##### Add template
 1. Create directory called templates in the app dir or in the project dir 
 2. add the path of that dir in the settings -> os.path.join(BASE_DIR,'templates') -> os is in the lib os (import os)
 3. create the .html files in the templates
 4. instead of HttpResponse in the views use render ->     return render(request,'pages/index.html')
 5. create link to the templates in urls.py of the project
##### Add static  
 1. create a directory in the project called static
 2. create directories as you want for every static file
 3. go to settings then in the static section write 
	 - STATIC_ROOT = os.path.join(BASE_DIR,'static)
	 - STATICFILES_DIRS = \[os.path.join(BASE_DIR,'first_project/static')]
 4. in the teminal write ./manage.py collectstatic
 5. in the base/html file write the tag 
 ```Django
{% load static %}
<link rel = "stylesheet" href = {% static 'path to .css' %}> 
 ```  

##### Django Template Language
``` Django Template Language
{# For Loop #}
{% for athlete in athlete_list %}
    <li>{{ athlete.name }}</li>
{% empty %} # returned if the list is empty
    <li>Sorry, no athletes in this list.</li>    
{% endfor %}

{# If Statement #}
{% if athlete_list %}
    Number of athletes: {{ athlete_list|length }}
{% elif athlete_in_locker_room_list %}
    Athletes should be out of the locker room soon!
{% else %}
    No athletes.
{% endif %}

{# Extends #}
{% extends "./base2.html" %}

{# Block #}
{% block sidebar %}
<ul>
    <li><a href="/">Home</a></li>
        <li><a href="/blog/">Blog</a></li>
    </ul>
{% endblock sidebar %}


{# Include #}
{% include "foo/bar.html" %}

{# URL #}
{# 127.0.0.1:8000/some-url-name/v1/v2 #}
{# some-url-name = /post/ #}
{% url 'some-url-name' v1 v2 %}


```
##### Filters 
``` Django Template LAnguage
  {{username | capfirst | truncatewords:3 | trancatechars:2 | lower}}
```


## Models


##### Add models
 1. create app for models
 2. go to the models in the app then 
 3. create a class that takes models.Model then 
 4. write the columns names (members) in the class
 *      the fields are equalled with models objects  
 ```Django
   EX:   
   name = models.   CharField(choices = <x> [(name1,name1) , (name2,name2)], verbose_name = 'name' , null = <bool> {#can be null (empty)#}, blank =<bool>{#not required#} , default = <value>,max_length = <num>)
 *                             IntegerField(choices = <x> [(name1,name1) , (name2,name2)], verbose_name = 'name' , null = \<bool> {#can be null (empty)#}, blank = \<bool>/*not required*/ , default = \<value>,max_digits = \<num>)
 *                             DecimalField(choices = \<x> \[(name1,name1) , (name2,name2)], verbose_name = 'name' , null = \<bool\> /*can be null (empty)*/, blank = \<bool>/*not required*/ , default = <value>,max_digits = <num> , decimal_places = <num>)
 *                             TextField(choices = <x> [(name1,name1) , (name2,name2)], verbose_name = 'name' , null = <bool> /*can be null (empty)*/, blank = <bool>/*not required*/ , default = <value>,)
 *                             ImageField(choices = <x> [(name1,name1) , (name2,name2)], verbose_name = 'name' , null = <bool> /*can be null (empty)*/, blank = <bool>/*not required*/ , default = <value>,upload_to = 'photos/%y/%m/%d')
 *                             BooleanField(choices = <x> [(name1,name1) , (name2,name2)], verbose_name = 'name' , null = <bool> /*can be null (empty)*/, blank = <bool>/*not required*/ , default = <value>)
 *                             DateField(default = datetime.now()) --> to use datetime.now() include  (from datetime import datetime)
 *                             TimeField(default = datetime.now()) --> to use datetime.now() include  (from datetime import datetime)
 *                             DateTimeField(default = datetime.now()) --> to use datetime.now() include  (from datetime import datetime)
 *                             OneToOneField(<the related class name>, on_delete = models.   CASCADE /*delete*/)
 *                                                                                           PROTECT /*keep it*/
 *                             ForeignKey(<the related class name>, on_delete = ...)
 *                             ManyToManyField(<the related class name>, on_delete = ...)
 ```                    
 5. add models in the admin panal                   
       1. go to admin.py in the app                            
       2. include the models -> from .models import \<class name>
       3. write admin.site.register(\<class name>)
 6. make migration for the models
       1. ./manage.py makemigrations
       2. ./manage.py migrate
 7. show the models content for users (if needed)
       1. create template for the models
  8. in the views.py in the models app include the model class -> from .models import \<class name>
 9. in the views.py use context to pass the models -> return render(request,'path to model template',/*context*/{'key':value})
 *          EX: return render(request,'products/products.html',{'pro':Product.objects.     all()  })
 *                                                                                         get(/*condition*/)
 *                                                                                         all().filter/filter(/*condition*/  __exact, __contains , __in = \[n1, n2, ..], __range = \[n1, n2])
 *                                                                                         all().order_by(/*field name*/)
 *                                                                                         all().count() --> returns int so make cast to string -> str()
 *                                                                                         all().exclude(/*condition*/)      
 10. in the template create a for loop then loop in the models and do what ever you want to display them for users                                                                                        
 11. If there is media(images) in the model 
        1. go to settings in the project       
        2. create a section called media
        3. write MEDIA_ROOT = os.path.join(BASE_DIR,'media')               
		        MEDIA_URL = '/media/'
        4. go to urls of the project then
        5. write   from django.conf import settings         
	        from django.conf.urls.static import static          
        6. add +static(settings.MEDIA_URL, documents_root = settings.MEDIA_ROOT) after the urlpatterns variable
        7. in the for that may be created in step 10 to show the image write EX: <img src="{{x.image.url}}" alt="">
        8. the media directory will be automatically created when we add a record to the model 

##### Object Relation Mapper (ORM)
