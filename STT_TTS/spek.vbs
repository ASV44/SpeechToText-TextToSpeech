Dim text, sapi
text="�� ����� ��������"
Set sapi=Createobject("sapi.spvoice")
with sapi
Set.voice=.getvoices.item(5)
end with
sapi.Speak text