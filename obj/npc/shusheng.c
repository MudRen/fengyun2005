// teacher.c
#include <ansi.h>

inherit NPC;

void create()
{
        
        string *order = ({"张", "王", "李", "赵", "孙", "徐", "郑", "周", "吴",
"蒋", "沈", "杨", "苗", "尹", "金", "魏", "陶", "俞", "柳", "朱"});
	string *orderr = ({"阿发", "拆捌", "裁答", "发胳", "妈唔",
"欧派", "机咖", "腊玛"});
        string *poem = ({"慈母手中线，游子身上衣。临行密密缝，意恐迟迟归。谁言寸草心，报得三春晖。\n",
        		"泪墨洒为书，将寄万里亲。书去魂亦去，兀然空一身。\n",
        		"一夕九起嗟，梦短不到家。再度长安陌，空将泪见花。\n",
        		"昔日龌龊不足夸，今朝放荡思无涯。春风得意马蹄疾，一日看尽长安花。\n",
        		"边地春不足，十里见一花。及时须遨游，日暮饶风沙。\n",
        		"长安落花飞上天，南风引至三殿前。可怜春物亦朝谒，唯我孤吟渭水边。\n",
        		"去春会处今春归，花数不减人数稀。朝笑片时暮成泣，东风一向还西辉。\n",
        	});



        set_name( order[random(20)] + orderr[random(8)], ({ "shusheng", "sheng" }) );
	
	set("title", "落第书生");
	set("gender", "男性" );
	set("age", random(20)+20);
	set("int", 26);
	set("long",
		"他以教书为业。\n");
		
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                CYN""+name()+"摇头晃脑地吟道："+poem[random(7)]+""NOR,
        }) );

	set("attitude", "peaceful");
	
	set_skill("literate",40);
	set_skill("dodge",50);
	
	set("combat_exp", 5000);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


int random_move()
{
        mapping exits;
        string *dirs;
	string thisdir;
        
        if (query_temp("random_move")>= 160 && query("startroom") && !query("no_return")) {
		if (return_home(query("startroom")))
			delete_temp("random_move");
		return 1;
	}
        if( !mapp(exits = environment()->query("exits")) ) 
	{
		destruct(this_object());
		return 0;
	}
        dirs = keys(exits);
	thisdir = dirs[random(sizeof(dirs))];
	this_object()->set("last_dir",thisdir);
        command("go " + thisdir);
        add_temp("random_move",1);
}
