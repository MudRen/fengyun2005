
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "斩蟒台顶");
        set("long", @LONG
此处便是斩蟒台顶。面北而立，碧海蓝天，云雾氤氲，一叶扁舟在浪涛上几个颠
簸起伏，消失不见。转过身，巍然南望，远处接天楼后竟隐隐约约还有不少亭台楼阁。
台顶盘旋着一条狰狞巨蟒，碧眼獠牙，如同活得一般，而八方斜斜插着数柄利剑，遥
指蟒首。
LONG
           );
        set("exits", 
           ([ 
       "down" : __DIR__"zhanmangtai",
	    ]));
		set("no_fly",1);
	set("objects", 
	   ([ 
			__DIR__"npc/sen":1,
	    ]));
/*       set("item_desc", ([
                "巨蟒": "一条婴儿臂腕一般粗细的巨蟒，獠牙碧眼，仔细查看，方才发现
竟是一座雕像，而蟒首似乎可以搬动。（move）\n",
                 "serpent": "一条婴儿臂腕一般粗细的巨蟒，獠牙碧眼，仔细查看，方才发现
竟是一座雕像，而蟒首似乎可以搬动。（move）\n"
        ])); 
*/
        set("outdoors", "baiyun");

	set("coor/x",0);
	set("coor/y",-1030);
	set("coor/z",0);
	setup();
}

void init()
{

//        add_action("do_move","move");
}

int do_move(string arg)
{       
        object me;
        int dodge;
       
        if (!arg ||(arg != "蟒首" && arg != "巨蟒"&& arg != "serpent")) 
                return notify_fail("你要搬什么东西？\n");
        me=this_player();
        dodge=me->query_skill("dodge",1);
        if (query("in_action")==1) 
                return notify_fail("巨蟒之首已经被推动过了。\n");
                
        message_vision(HIC"\n$N神情严峻，缓缓推动巨蟒之首．．．．\n\n"NOR,me);
        message_vision(HIR"\n刹那之间，缓缓移动的巨蟒之首突然张大血盆巨口，两颗如同利箭一般的
尖牙向$N激射而来。。。\n\n"NOR,me);
        if (dodge<80)
        {
                message_vision(HIC"\n$N惊叫一声，使出浑身解术，闪转腾挪，但终于不及钢牙之速．\n\n"NOR,me);
                message_vision(HIR"\n$N但觉胸口血光一闪，钢牙竞已惯胸而过．．．．\n
$N低下头，无法置信的看着胸口两点血渍渐渐散开，扑地而死。\n"NOR,me);
                me->die();
        }
        else
        {
                message_vision(HIC"\n$N嘿然一笑，身形疾如闪电，躲过两颗利牙。。\n\n"NOR,me);
                message_vision(HIW"\n钢牙擦着$N胸口激射而过．．．．\n\n"NOR,me);
                me->start_busy(5);
                if (me && environment(me) == this_object())
                {
                        call_out("shoot_me", 3, me);
                }
                else
                        remove_call_out("shoot_me");
        }
        return 1;
}

void shoot_me(object me)
{
	object box,cloth,seal,hat;
        int dodge;
        int kee;
        dodge=me->query_skill("dodge",1);
        kee=(int) me->query("max_kee")/2;
        message_vision(HIC"\n$N身形未定，突然蟒台八方利剑寒光乍起。。\n\n\n"NOR,me);
        if(dodge<100)
        {
                message_vision(HIR"\n近在咫尺的八柄利剑强努一般疾射而至，$N惨叫一声，八把长剑透体而入。\n\n"NOR,me);
                message_vision(HIR"\n$N浑身血流如注，脸色如同白纸一般，一个踉跄，倒在地上。\n\n"NOR,me);
                me->receive_wound("kee", kee);
                me->unconcious();

        }
        else
        {
        message_vision(HIW"\n$N提气丹田，纵身而起，仿佛鹞子般轻轻巧巧躲过利剑。\n\n"NOR,me);
        message_vision(HIC"$N飘然落下，但见八把长剑深深插入巨蟒之身，兀自嗡嗡颤动。\n"NOR,me );
        message_vision(HIY"\n\n$N凝目朝巨蟒望去，紧绕的蟒身已经松开，露出一个描金箱子。\n"NOR,me);
        message_vision(HIW"\n\n$N神色一凛，小心地把描金箱子收入怀中。\n"NOR,me);
        box=new(__DIR__"obj/goldbox");
        cloth=new(__DIR__"obj/emperor_cloth");
        seal=new(__DIR__"obj/jade_seal");
        hat=new(__DIR__"obj/sinny_hat");
        cloth->move(box);
        seal->move(box);
        hat->move(box);
        box->move(me);
        set ("in_action",1);}
}


void reset()
{

::reset();
        if(query("in_action")) set("in_action",0);
        
} 



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
