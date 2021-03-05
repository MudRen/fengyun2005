inherit ROOM;
void create()
{
        set("short", "大巴札");
        set("long", @LONG
巴扎就是集市的意思，乌拉泊的“巴扎”早在多年前就是“丝绸之路”上最有
名的地方。每逢赶“巴扎”时，各种土特产品，手工艺品，瓜果蔬菜等一起向“巴
扎”涌来。随时随地都可以看到头戴花帽，赶着小毛驴车，身着盛装的人。
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"bazha1",
  "northwest" : __DIR__"bazha2",
  "south" : __DIR__"nanmen"
]));
        set("objects", ([
        __DIR__"npc/swaiter1" : 1,
	__DIR__"npc/swaiter2" : 1,
        __DIR__"npc/swaiter3" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
