inherit __DIR__"no_killing_place";
void create()
{
        set("short", "农家");
        set("long", @LONG
这是一户很简朴的农家，门敞开着，屋内陈设十分简单，而且静悄悄的，主人
好象出去做活了。屋内竹床上铺着简单的被褥，上面摆了一个已经很旧了的针线篮。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"west" : __DIR__"nongjia",
	]) );

   	set("objects", ([
      		__DIR__"obj/basket": 1,
   	]) );

	set("no_magic", 1);
	set("coor/x",15);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void reset()
{
	object *inv;
        object item1, item2, item3, basket;
        int i, needle, thread;
        
        ::reset();
        basket = present("basket", this_object());
        inv = all_inventory(basket);
        for (i=0;i<sizeof(inv);i++) {
        	if (inv[i]->query("name")=="绣花针") needle=1;
        	if (inv[i]->query("name")=="细麻线") thread=1;
        }
        if (!needle) {
        	item1 = new(__DIR__"obj/needle");
        	item1->move(basket);
        	}
        if (!thread) {
        	item2 = new(__DIR__"obj/string");
        	item2->move(basket);
        	}
}
