// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"黄金塔顶"NOR);
	set("long", @LONG
这里是黄金塔的顶层，从外面看似乎很狭小，但身处其中，倒反而觉得十分 
宽敞，除了满眼的黄金外，便没有别的了。
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"down" :  __DIR__"jq3-tower4",
	]));
        set("item_desc", ([

	]) );
	set("objects", ([
                __DIR__"npc/jq3-shangguan" : 1,
                __DIR__"npc/jq3-chixu" : 1,
                __DIR__"npc/jq3-meihuadao" : 1,

 	]) );
	setup();
	
}


string *event1_msg=	({
	
	WHT"\n赤虚子捋捋白须，搂着林仙儿哈哈大笑道：凡夫俗子终归是凡夫俗子，
来来来，让老道我送你到极乐世界走一遭。。\n"NOR,
	
	HIR"话音未落，突然，从四方飘来四个人，僧道尼儒。 
“妖道赤虚，今日是你元神俱灭之日！” 
兴国大师，丁乘风，丁白云三人合力将手中“天，地，人”三味灵符之火 
汇聚到飞刀之上。。。 \n"NOR,
	
	HIR"一把火红的飞刀，燃烧着的飞刀，
	
	小李飞刀！ \n"NOR,

        HIR"\n小李飞刀，例不虚发！  \n\n"NOR,

    	HIW"赤虚子浑身的须发突然失去了生命，枯萎，脱落。 
浑身白嫩光滑的肌肤刹时在收缩，干瘪，燃烧。。。  \n"NOR,
    	
    	HIW"赤虚子惨叫一声，阳光下，尽已燃烧的无影无踪，一点灰烬都没留下。 
林仙儿也惨遭真火之劫，美丽的肌肤收缩，燃烧。。。

	林仙儿痛苦地嘶叫着，翻滚着。 \n"NOR,

    	HIW"终于，林仙儿挣扎了几下倒在地上，死了。 \n"NOR,

});


void event1(object me, int count)
{
	object lu, meihuadao;
	object who, *inv;
	int i;
	mapping data;
	
	lu = present("chi xu", this_object());
	meihuadao = present("meihuadao",this_object());
		
	if (!lu || !meihuadao)	return;
			
	message_vision(event1_msg[count]+"\n",me);
	if(++count==sizeof(event1_msg))
	{
		destruct(lu);
		meihuadao->die();
		CHANNEL_D->do_sys_channel(
			"info",sprintf("%s，%s率群雄于金钱帮黄金塔一役中大获全胜，千古流芳！", NATURE_D->game_time(),
				me->query("name")) );
		
		// TIME to REWARD ALL
		inv = all_inventory();
		for (i = 0;i<sizeof(inv);i++)
		{
			if (!userp(inv[i]))	continue;
			who = inv[i];
			
			if (REWARD_D->check_m_success(who,"勇入少林"))
			if (!REWARD_D->check_m_success(who,"决战黄金塔"))
			{
				REWARD_D->riddle_done(who, "决战黄金塔",500, 1);
			
				data = ([
					"name":		"黄金塔：决战黄金塔",
					"target":	who,
					"att_1":	"str",
					"att_1c":	1,
					"mark":		1,
				]);
			REWARD_D->imbue_att(data);
			}
		}
		
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}

