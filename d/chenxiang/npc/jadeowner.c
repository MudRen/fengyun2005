#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
    	set_name("郑甲", ({ "zhengjia", "zheng" }) );
    	set("gender", "男性" );
    	set("age", 39);
    	set("title", "珠宝商");
    	set("long", "这里卖的玉都是上等的缅玉，而且价钱合理。\n");
    	set("combat_exp", 17000);
    	set("attitude", "friendly");
    	
    	set_skill("dodge", 100);
    	set_skill("parry", 120);
    	set("vendor_goods", ([
	        __DIR__"obj/jade1":120,
	        __DIR__"obj/jade2":120,
	        __DIR__"obj/jade3":120,
	        __DIR__"obj/jade4":120,
        ]) );
    	set("inquiry", ([
        	"玉脖套" : 	"我这没有的卖，不过你可以买几块缅玉弧然后找石匠加工嘛。\n",
        	"yubotao" : "我这没有的卖，不过你可以买几块缅玉弧然后找石匠加工嘛。\n",
        	"王石匠" : 	"王石匠？他不会理你的，除非你认得他的大恩人。\n",
        	"wang" :	"王石匠？他不会理你的，除非你认得他的大恩人。\n",
        	"大恩人":	"哈哈，不就是那个“眼皮上落苍蝇”么。\n",
        	"恩人":		"哈哈，不就是那个“眼皮上落苍蝇”么。\n",
        	"古董三":	"古董三，古董三，原名叫英穷死，就是那个有名的探宝大王了。\n",
        ]));
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( " 郑甲笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，玉可以消灾，买几块吧？ \n");
                        break;
                case 1:
                        say( " 郑甲笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，玉是吉祥之物，多买几块吧。 \n");
                        break;

        }
}


int accept_object( object who, object item){
		
		if (item->query("name") == HIM"紫晶宝石"NOR && item->query("jile")==1){
			if (REWARD_D->riddle_check(who,"紫晶之谜")==2 
				|| REWARD_D->riddle_check(who,"紫晶之谜/郑甲")) {
				command("shake");
				command("say 你还是另找高人吧。");
				return 0;
			}
			
			
			message_vision(CYN"$N拿起"+item->query("name")+NOR+CYN"掂了几下，又拿出个镜片端详片刻，眉头紧锁。\n"NOR, this_object());
			ccommand("hmm");
			ccommand("say 不可能，不可能，这紫晶如何会有如此纹理，没见过。");
			REWARD_D->riddle_set(who,"紫晶之谜/郑甲",1);
			
			if (sizeof(who->query("riddle/紫晶之谜"))==4) {
				tell_object(who, CYN"\n"+name()+CYN"说：只有一个人会知道这块宝石的来历，他的名字叫古董三。
据说此人自三岁起就跟着他老爹在古墓里打转，这黑道白道上流转的宝物，
没有他不知道来历的，他一定知道这宝石的底细。\n");
				REWARD_D->riddle_set(who,"紫晶之谜",2);
			}
			return 0;
		}
			
		if (item->query("thief_obj")){
			command("say 小店不收来历不明之物。");
			return 0;
		}
				
}

void reset()
{
    set("vendor_goods", ([
        __DIR__"obj/jade1":120,
        __DIR__"obj/jade2":120,
        __DIR__"obj/jade3":120,
        __DIR__"obj/jade4":120,
        ]) );
}
