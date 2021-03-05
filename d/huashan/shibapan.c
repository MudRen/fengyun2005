
inherit ROOM;

void create()
{
        set("short", "十八盘");
        set("long", @LONG
此处山势陡峭，盘山土路陡峭艰辛，路随山势曲折盘环，十有八折盘山而上，
路旁荆棘丛生，你不时的被荆棘牵挂衣冠。
LONG
        );
    set("exits", ([ 
  		"northeast" : __DIR__"shaluo",
  		"southeast" : __DIR__"shibapan1",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-15);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init(){
	object me, jingji, obj;
	me = this_player();
	if(me->query("宿命B/武当_枫叶") && !present("jingji", this_object())) {
		jingji = new(__DIR__"obj/jingji");
		jingji->move(this_object());
		obj = new(__DIR__"obj/book");
		obj->move(jingji);
	}
}
