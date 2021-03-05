inherit __DIR__"no_killing_place";
void create()
{
    set("short", "密林");
    set("long", @LONG
高大的树木为了争取更多的阳光而努力向上伸展着，少量的阳光透过树冠，所
以即使是白日林中也显得很昏暗。树的下面长满了不知名的矮小的植物，树干上爬
满了各式各样的藤萝，有的还开着鲜艳的花朵。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"linjian",
        "east" : __DIR__ "forest",
        ]));

    set("outdoors","taoyuan");
    set("item_desc", ([
        "藤萝":"缠绕在树干上的藤萝长的十分茂盛，藤萝的皮柔韧而结实。\n"
          "你可以用刀砍（ｃｈｏｐ　ｖｉｎｅ）。\n",
        "vine":"缠绕在树干上的藤萝长的十分茂盛，藤萝的皮柔韧而结实。\n"
          "你可以用刀砍（ｃｈｏｐ　ｖｉｎｅ）。\n",
	]) );
    set("no_magic", 1);
	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",0);
    setup();
}

int do_cut(string arg)
{
    object obj;
    object me;

    if(arg && (arg=="vine" || arg=="藤萝"))
    {
	me = this_player();
	obj = me->query_temp("weapon");
	if( !obj ) 
	{
            write("你空着手，怎么砍？\n");
            return 1;
	}
	if( obj->query("flag") == 4)
	{
            if(!query("marks/gone"))
            {
                object ob;
                message_vision(sprintf(
                    "$N挥动%s，砍下了一条长长的藤萝。\n",obj->name()),me);
                set("marks/gone",1);
                ob=new(__DIR__"obj/tengluo");
                ob->move(me);
            }
            else message_vision(sprintf(
            "$N用手中的%s一顿乱砍，可是藤萝已经被砍得差不多了。\n",obj->name()), me);
	}
	else message_vision(sprintf(
            "$N用手中的%s向丛生的藤萝一顿乱砍，不过%s太不称手了，什么也没砍下来。\n",obj->name(),obj->name()), me);
    }
    else write("你要砍开什么？\n");
    return 1;
}

void init()
{
	::init();
    add_action("do_cut","chop");
}

void reset()
{
    ::reset();
    delete("marks/gone");
}
