inherit ROOM;

void create()
{
	set("short", "浣花溪");

	set("long", @LONG
一道清澈见底的泉水从两旁的山中溅落下来，嘈嘈切切错杂弹地，大珠小珠似
雨打玉盘，两旁山花烂漫，溪水中各色缤纷的花瓣随着溪水静静地流淌，一切美丽
如画。泉水浅浅可行，逆流而上，但见白云幽幽，空山无语。
LONG);

	set("type","waterbody");
       set("outdoors", "wolfmount");
	set("exits",([
         "southeast":__DIR__"brook2",
         "northwest":__DIR__"brook",
	]) );
	set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
void init()
{
	if(interactive(this_player()))
	{
		remove_call_out("dropflower");
		call_out("dropflower",random(10)+10,this_player());
	}
}
int dropleaf(object me)
{
	object dropflower;
	if(me)
	if(environment(me) == this_object())
	{
		tell_object(me,"一瓣落花随溪水悠悠飘了过来．．．．\n");
        dropflower = new(__DIR__"obj/dropflower");
		dropflower->move(this_object());	
	}
}
