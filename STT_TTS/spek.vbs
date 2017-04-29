Dim text, sapi
text="Ты такая красивая"
Set sapi=Createobject("sapi.spvoice")
with sapi
Set.voice=.getvoices.item(5)
end with
sapi.Speak text