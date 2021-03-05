// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "养性堂");
        set("long", @LONG
修练内力的绝佳场所，少林心法全源自禅功，所以静心养性，清静无为是学成
少林内功的必要条件，在这里修习内功，锤炼内力都是事半功倍的（ｄａｚｕｏ），
可惜地方很小。远眺窗外，依稀可以看见西北方的邸园精舍。
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"cj",
  "northeast" : __DIR__"banruo",
]));
	set("no_magic", 1);
	set("coor/x",-10);
	set("coor/y",110);
	set("coor/z",20);
	setup();
}
void init()
{
        add_action("do_jump", "修习");
        add_action("do_jump", "dazuo");

}

int do_jump()
{
        object me;
        int wait;
        me = this_player();
        wait = random( 40 - (int)(me->query("con"))) * 2;
        if ( wait <= 20) wait = 21;
        message_vision("$N＂噗嗵＂一声盘腿坐在地下．．\n",me);
        tell_object(me,"你感到内力在体内回荡．．．\n");
        remove_call_out("curehimup");
        call_out("curehimup", wait, me);
return 1;
}
void curehimup(object me)
{
        int force;
        force=(int)me->query("max_force");
if( me && environment(me) == this_object())
        {
        message_vision("$N的内力全恢复了！！\n", me);
        me->set("force", force);
        }
return;
}

