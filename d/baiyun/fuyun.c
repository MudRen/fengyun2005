//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "浮云货栈");
    set("long", @LONG
这是世上独一无二的一家货栈，因为这里有世上独一无二的最漂亮的老板娘，也
有独一无二的老板，朱停；朱停并不做生意，他认为无论做什么生意，开什么店，都
难免有蚀本的时候，他绝不能冒这个险，更何况他也从没有做老板的本钱，但他有个
会做老板的老板娘，所以朱停通常只在内室的竹椅上打盹，盹打得多了，身上的肉自
然也多了，而胖的人看起来总是很有福气的样子，所以朱停天生似乎就是个做老板的
命，虽然，他不愿意。
LONG
    );
    set("exits",
      ([
	"south" : __DIR__"skystreet3",
	"north" : __DIR__"fuyunneishi",
      ]));
    set("objects",
      ([
	__DIR__"npc/beautyboss" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-150);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
