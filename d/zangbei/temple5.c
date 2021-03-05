inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "直共寺");
        set("long", @LONG
直共寺为“藏地三宝”之一的帕木竹巴建造，寺内存有口含帕竹亲身牙齿的自
塑雕像一尊。该寺古木参天，松柏常青，环境幽雅，到处鸟语花香。成群结队的藏
马鸡随处可见，犹如家养。寺内终年香火不断，前来朝圣者络驿不绝。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"wild6",
		
	]));
        set("item_desc", ([
        	"tree":	"直共寺古木参天，每棵都有上百年的历史。\n",
        	"古木":	"直共寺古木参天，每棵都有上百年的历史。\n",
        	"松柏":	"就是松树和柏树了。。。\n",
        	"柏树": "柏树不高，弯弯的成拱桥状。\n",
        	"pine": "这棵松树怕是在建寺的那年栽下的，盘曲的丫枝，扇形的簇叶，遮住了半个天空。\n",
        	"松树": "这棵松树怕是在建寺的那年栽下的，盘曲的丫枝，扇形的簇叶，遮住了半个天空。\n",
    	]));
        
        set("objects", ([
        	__DIR__"npc/chicken":	2,
        	__DIR__"obj/statue5":	1,
        	__DIR__"npc/monk5":	1,
	]) );
        set("coor/x",-1900);
        set("coor/y",720);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}

void init(){
	add_action("do_around","around");
	add_action("do_climb","climb");
}

void reset()
{
	object statue,incense;
               
        ::reset();
        statue = present("statue", this_object());
        if (!present("incense",statue)) {
        	incense=new(__DIR__"obj/incense");
        	incense->move(statue);
	}
}


int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg) {
		tell_object( me, "你想爬什么？\n");
		return 1;
	}
	
	if (arg == "tree" || arg == "树"){
		tell_object( me, "嗯，那么爬哪棵树呢？\n");
		return 1;
	}
		
	if (arg=="pine"|| arg=="松树" || arg == "大松树") {
//		if (!me->query_temp("marks/zangbei/马鸡上树")) 
//			return notify_fail("无缘无故爬什么树？\n");
		room=find_object(__DIR__"pine1");
		if (!objectp(room)) room=load_object(__DIR__"pine1");
		message_vision("$N手脚并用，敏捷地爬上了松树。\n",me);
        tell_room(room, this_player()->name() + "从树下爬了上来。\n");
        this_player()->move(room);
      	return 1;
      }
      
      return notify_fail("这个大概没法爬。\n");
}

int do_around(){
	
	object me = this_player();
	object tong = me->query_temp("weapon");
	
	
	if (!tong || tong->name() != "转经筒")
		return notify_fail("没有经筒，如何转经？\n");
	
	if (me->is_busy())
		return notify_fail("你现在忙得很，没空转经。\n");
				
	message_vision(YEL"$N转动着手中的小经筒，虔诚地颂着经文，绕着"
		+this_object()->query("short") + "慢慢走了一圈。\n"NOR, me);
	me->start_busy(1);
	
	if (me->query("marks/转经") ||
		REWARD_D->riddle_check(me,"灵童转世")!=1
		|| me->query_temp("zhuanjing/zhigong"))	return 1;
		
	me->add_temp("zhuan_around",1);
	
	if (random (me->query_temp("zhuan_around"))>= 10)
	{
		tell_object(me,WHT"\n你在"+ query("short")+"转经完毕，对密宗佛法的了解略有提高。\n"NOR);	
		me->delete_temp("zhuan_around");
		me->set_temp("zhuanjing/zhigong",1);
		
		if (mapp (me->query_temp("zhuanjing")))
		if (sizeof(me->query_temp("zhuanjing")) == 4)
		{
			REWARD_D->riddle_set(me,"灵童转世",2);
			me->set_skill("lamaism",me->query_skill("lamaism",1)+1);
			tell_object(me,HIC"你的密宗佛法提高了一个等级。\n"NOR);			
			me->set("marks/转经",1);
			me->delete_temp("zhuanjing");
		}
	}
	return 1;
}
	
	