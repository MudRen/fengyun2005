inherit ROOM;

void create()
{
	set("short", "平台");
	set("long", @LONG
在这里有一个小小的平台，你可以在这稍作休息。平台一侧是悬崖，另一侧是
峭壁，壁上爬满了青藤，拨开藤蔓，后面隐隐约约有一个山洞，洞里很黑，伸手不
见五指。洞口贴着块牌子，从风化的程度来看，这个山洞已经被废弃多年了。
LONG
	);
        set("item_desc", ([
      		"up": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
      		"mountain": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
      		"山": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
      		"牌子":	"牌子上面歪歪扭扭地写着“炼丹重地，闲人莫入”\n",
      		"sign":	"牌子上面歪歪扭扭地写着“炼丹重地，闲人莫入”\n",
        ]) );
	set("exits",([
		"in" : AREA_MAZE"cave-entry",

	]));
	
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",-10);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
//      object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        me = this_player();
        if( arg == "up" || arg == "山" || arg == "mountain")
        {
        	message_vision("$N慢慢地往山上爬去。\n", me);
        	me->move(__DIR__"hole.c");
        	return 1;
        }
        else if( arg == "down") {
        	message_vision("$N慢慢地往山下爬去。\n", me);
	        me->move(__DIR__"road5.c");
      		return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}

/*
一个黑漆漆的山洞，黑沉沉的一眼望不到底。两侧的石壁上生满的苔藓，
摸起来又湿又滑。这石洞似乎是人工开凿的，从四周的石壁上仍能看出斧凿的
痕迹。你站在这里，一股恐惧由然而生，似乎身体随时都会被这片黑暗吞噬掉。
*/