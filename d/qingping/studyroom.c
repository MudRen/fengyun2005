//XXDER
inherit ROOM;
void create()
{
        set("short", "书房");
        set("long", @LONG
这里就是白三空的书房，里面足足两柜的书，白三空武功修为已臻化境，没想
到于文一道，也如此精深，室内墙上挂了几幅字画，画不知出自何人的手笔，那几
幅字却似白三空的亲笔。屋内靠墙处有一张红木书桌，书桌前摆了一张椅子。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "south" : __DIR__"garden",
   ]));

   set("item_desc", ([
      	"writing": "只见字迹刚中带柔，宛如行云流水一气呵成。\n",
      	"字": "只见字迹刚中带柔，宛如行云流水一气呵成。\n",
   ]) );

   set("objects", ([
      __DIR__"obj/desk": 1,
      __DIR__"obj/wall": 1,
      __DIR__"npc/qingm" : 1,
   ]) );

	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void reset()
{
//	   object *inv;
	   object item1, item2, desk, wall;
	   ::reset();
	   	   
   		desk = present("desk", this_object());
   		wall = present("wall", this_object());

	   if (!present("silk bag", desk)) {
	   		item2 = new(__DIR__"obj/bag");
	      	item2->move(desk);
	   }
	   	
	   if (!present("letter", desk))	{
			item1 = new(__DIR__"obj/letter");
	      	item1->move(desk);
	   }
	   
	   if (!present("kite",wall)) {
	   		item1 = new(__DIR__"npc/obj/kite");
	      	item1->move(wall);
	   }
   
}