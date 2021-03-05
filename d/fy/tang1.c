inherit ROOM;
void create()
{
    set("short", "恩怨堂");
    set("long", @LONG
堂正中檀木香案，案上燃着几炷香，整间屋檀香袅袅。凡是入此堂的人，都愿
把以往恩怨一笔勾消。如果你有愧你的所作所为，想忘记已往的恩恩怨怨，重新做
人，只需在这里跪下（ＫＮＥＥＬ）。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"jhuang",
      ]));
    set("no_magic",1);
    set("NONPC",1);
    set("coor/x",-160);
    set("coor/y",100);
    set("coor/z",0);
    setup();
}

void init()
{
    add_action("do_kneel", "kneel");
}

int do_kneel()
{
    this_player()->remove_all_killer();
    message_vision("$N跪倒在地，决定忘记以前所有的仇家．\n",this_player());
	this_player()->perform_busy(3);
	return 1;
}
