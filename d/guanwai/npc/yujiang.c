// jademaker.c
#include <ansi.h>
int stone();
inherit NPC;

void create()
{
	set_name("罗达成", ({ "luo", "jade maker", "玉匠" }) );
	set("gender", "男性" );
	set("title", "老石匠");
	set("age", 55);
	set("long", "
他有一双锐利的眼睛，那双眼可以分辨顽石和美玉；他还有一双巧手，
而那双手则可以把玉石变成最精美的玉器。\n");
	set("combat_exp", 50000);
	set("env/wimpy", 10);
	set("chat_chance", 1);
	set("chat_msg", ({
		"老玉匠自语道：“上次小玉送来的碧螺春味道纯正。”\n",
		"老玉匠喃喃自语道：“五色灵石，五色灵石，难道那只是一个传说吗？”\n",
	}) );
	set("inquiry", ([
        	"stone" :	(: stone :),
        	"五色灵石" : 	(: stone :),
        	"碧螺春":	"老朽别的没什么爱好，就爱喝些好茶，龙井茶，狼山茶，还有那黄山的云雾茶。。。\n",
        	"古董三":	"古董三，古董三，原名叫英穷死，就是那个有名的探宝大王了。\n",
    	]) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void init(){
    	int i, left;
    	object me;
    
    	::init();
    	me = this_player();
    	i = me->query("marks/凝露黄石_Timeyantai");
		if (!i)	return;
      	remove_call_out("yantai");
      	call_out("yantai", 1, me);   
    
}


int stone(){
	object me;
	me = this_player();
	if(this_object()->is_fighting() || this_object()->is_busy()) {
		return 0;
	}
	message_vision(YEL"$N微微一笑道：“传说，有五种灵异的宝石，任何人如果能得到其中的一
种，都能从中得到神奇的灵异力量。不过，这事儿我也只是听说的，风云城里
人来人往，你可以到那儿去打听一下。”\n"NOR, this_object());
	return 1; 	
}

void yantai(object me) {
    	object obj;
    	int i, left;
    	
    	if (!me || environment(me)!= environment(this_object()))	return;		
    	i = me->query("marks/凝露黄石_Timeyantai");
		if (!i)	return;
			
		left = i + 4320 - time(); // 72mins 一次，一天勤奋的at least 能做 10 次, 10silver 砚台
				
    	if (left >0) {
    		tell_object(me,"老石匠抬头看看，对你说：你来早了，还需要等"+ (left/60) +"分钟。\n");
    		return;
    	}
    	
    	//	L30 以下的dummy们，你们是拿不到的。 1/10 机会出第一步。
    	if (!random(10) && F_LEVEL->get_level(me->query("combat_exp"))> 30) {
        	message_vision(YEL"
老石匠叹了口气对$n说道：“老了，手也不听话了，砚台做坏了，
这是我家传砚台，就送给你吧。”\n"NOR,this_object(),me);
    		obj = new(__DIR__"obj/yantai2");
    		REWARD_D->riddle_set(me,"凝露黄石",4);	// 如果做了后面的再回来, reset here.
    	} else {
        	message_vision(YEL"老石匠说道：“这位" + RANK_D->query_respect(me) + "，这是加工好的砚台。\n"NOR, 
                	this_object(), me);
        	if(me->query("marks/凝露黄石_Coloryantai") == "青") {
            		obj = new(__DIR__"obj/yantai");
        	} else if (me->query("marks/凝露黄石_Coloryantai") == "紫红") {
            		obj = new(__DIR__"obj/yantai1");
        	}
    	}
    	obj->move(me);   
    	me->delete("marks/凝露黄石_Coloryantai");
    	me->delete("marks/凝露黄石_Timeyantai");
    	REWARD_D->riddle_done(me,"加工石料",10,1);	// 可无限重复拿
}



int accept_object(object me, object ob){
	object dog;
	string color;
	
	if (ob->query("name") == HIM"紫晶宝石"NOR && ob->query("jile")==1){
			
			if (REWARD_D->riddle_check(me,"紫晶之谜")==2 
				|| REWARD_D->riddle_check(me,"紫晶之谜/罗达成")) {
				command("shake");
				command("say 你还是另找高人吧。");
				return 0;
			}
			
			message_vision(CYN"$N拿起"+ob->query("name")+NOR+CYN"掂了几下，又拿出个镜片端详片刻，眉头紧锁。\n"NOR, this_object());
			ccommand("hmm");
			ccommand("say 老夫凿玉五十多年，还从来没见过如此奇怪的紫晶，你还是另寻高人吧。");
			REWARD_D->riddle_set(me, "紫晶之谜/罗达成",1);
			
			if (sizeof(me->query("riddle/紫晶之谜"))==4) {
				tell_object(me, CYN"\n"+name()+CYN"说：只有一个人会知道这块宝石的来历，他的名字叫古董三。
据说此人自三岁起就跟着他老爹在古墓里打转，这黑道白道上流转的宝物，
没有他不知道来历的，他一定知道这宝石的底细。\n");
				REWARD_D->riddle_set(me,"紫晶之谜",2);
			}
			return 0;
	}
					
	if(ob->query("名茶")){		// 2 types in fy2005 now...
		message_vision("$N拿着茶叶放到鼻子底下嗅了嗅，露出满意的笑容。\n", this_object(), me);
        message_vision("$N说道：多谢这位" + RANK_D->query_respect(me) + 
",老朽不才，你如果在加工玉石方面有需求，老朽还略知一二。 \n", this_object(), me);
    
        if (!REWARD_D->riddle_check(me,"加工石料") && !REWARD_D->check_m_success(me,"凝露黄石"))
           	REWARD_D->riddle_set(me,"加工石料",1);	// 这一步不需要采石。
	
	
	} else if( ob->query("砚台料") == 1 ){
	    	
	    	if (REWARD_D->check_m_success(me,"凝露黄石")) {	// not redoable
				message_vision("$N说：我不是已经把祖传的砚台给你了么，你忘了么？\n", this_object());
				return 0;
			}
	    	
	    	if (REWARD_D->riddle_check(me,"加工石料")==2)
	    	{
	    		message_vision("$N说：“不急，不急，你的上块玉料还没加工好呢。”\n", this_object());
	    		return 0;
	    	}
	    		    	
	    	message_vision("$N轻轻在" + ob->name() + "叩了两下，笑道:“不错， 不错，这可以做一个上好的砚台。”\n", this_object(), me);
        	if(REWARD_D->riddle_check(me,"加工石料")==1) {
	            	message_vision("$N说道：“这位" + RANK_D->query_respect(me) + "三天后来取砚台吧。”\n", this_object(), me);
	            	color = ob->query("color");
		        REWARD_D->riddle_set(me,"加工石料",2);
		        me->set("marks/凝露黄石_Timeyantai", time());
		        me->set("marks/凝露黄石_Coloryantai", color);
	    	}else {
	        	message_vision("老玉匠说道：“不过，老朽近来胃口不好，不再接活了。”\n", this_object(), me);
	        	return 0;
	    	}
	} else if (ob->name()==YEL"龙井茶"NOR || ob->name()==GRN"狼山茶"NOR) {
		message_vision("$N说：“茶是上好的名茶，不过，放在店里时间似乎长了，不新鲜喽。”\n",this_object());
		return 0;
	} else if (ob->name()=="云雾茶") {
		message_vision(CYN"$N呸的一声说：“茶是好茶，可惜，有血腥之气！”\n"NOR,this_object());
		message_vision(CYN"$N吹了声口哨，屋里跳出一只牧羊狗。\n"NOR,this_object());
		command("say 虎子，替我赶他出去。");
		if (!dog=present("shepherd dog",environment(this_object()))) {
			dog=new(__DIR__"sheepdog");
			dog->move(environment(this_object()));
		}
		dog->fight_ob(me);
		me->fight_ob(dog);
		return 0;	
	}else {
		message_vision("老玉匠摇头说：“我不需要这个。”\n", me);
	    	return 0;
	}	
	return 1;
}

