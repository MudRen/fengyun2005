#include <ansi.h>
inherit NPC;


int quest();
int change_area();
int change_maze();

void create()
{
	object weapon;
   	set_name("垂笠老僧", ({ "chuili seng", "seng" }) );
	set("gender", "男性" );
	set("age", 191);
	set("title", BLU"来历不明的"NOR);
	set("long","
没有人注意到什么时候起，城隍庙中多了这一位垂暮僧人挂搭，即使有人怀疑
过他的来历，也会被老僧一身阴森森的萧杀之气打消找麻烦的念头。他终年带
着一顶破旧的斗笠挡住泰半面容，肮脏的僧衣袍袖上绣着十三把小剑，看向他
时，你总会感觉到被笠下看不见的冰寒目光微微刺痛。\n");
	
	set("combat_exp", 2000000);
	set("busy_immune",4);
	
	set("attitude", "friendly");
	set("per",1);
	set("NO_KILL","垂笠老僧冷冷地看了你一眼，你禁不住浑身一抖，战意全消。\n");
	set_skill("magic", 200);
	set_skill("sheolmagic", 200);
	map_skill("magic","sheolmagic");

	set("inquiry", ([
	       	"神秘组织": (: quest :),
	       	"组织": 	(: quest :),
	       	"help": 	(: quest :),
	       	"job": 		(: quest :),	
	       	"task":		(: quest :),
	       	"找不到":	(: change_area :),
    		"lost":		(: change_area :),
    		"fail":		(: change_maze :),
    		"失败":		(: change_maze :),
    ]) );
		
	setup();
	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("肮脏的僧袍", ({ "monk cloth","cloth" }) );
	weapon->set("long","一件看不出原本颜色的肮脏僧袍，你注意到僧袍一角绣着十三把小剑。\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/armor/hat");
	weapon->set_name("宽大斗笠", ({ "hat" }) );
	weapon->set("long","一顶破破烂烂的斗笠。\n");
	weapon->set("value",0);
	weapon->wear();
}

int quest()
{
	string *area = ({ 	
		"huangshan", "huashan", "songshan", "palace", "laowu", 
		"resort", "qianfo", "qingping", "taoguan", "taoyuan", 
		"xinjiang","wanmei","eren",		
		"chuenyu", "taishan", "guanyin","wolfmount","qianjin",
		"biancheng", "zangbei","baiyun" ,"bat","changchun"});
	
	string *c_area =  ({"黄山","华山","嵩山","帝王谷","冰封小镇",
				"铁雪山庄","千佛山","清平山庄","三清山","桃源村",
				"新疆", "万梅山庄","恶人谷",
			    "黑松山","泰山","天枫山庄","狼山","千金楼", 
			    "边城", "藏北","白云岛","蝙蝠岛","长春岛",
			    });
	
	string *word1 =  ({
	"铁", "铜", "银", "魔", "黑", "刚", "石", "钢", "鬼", 
			    });
	string *word2 =  ({
	"爪", "手", "枪", "刀", "剑", "戟", "脚", "拳", "影", 
			    });
	string *word3 =  ({
	"狼", "虎", "豹", "熊", "狮", "鳄", "象", "猴", "鹰", 
			    });
	string *word4 =  ({
	"牙", "纹", "鼻", "魂", "腾", "翔", "斑", "吼", "轮", 
			    });
	string *word5 =  ({
	"帮", "派", "盟", "团", "军", "宫", "山", "林", "功", 
			    });
	string arg, room_name, *files,orig_name;
	int i, n, m, nn, mm, size, reward, exp, num,chance;
	object room, silver,room2;
	object me = this_player();
	mapping quest,*s_quest;
	string	*act = ({ " ", "此事机密无比，你需单身前往", "该处甚为凶险，最好找个帮手","该处极为凶险，最好携三两帮手同行",});
	string	*aa  = ({ " ", "单身", "结伴", "聚三二人" });			
	object *dungeon_list;

//	testing
//	me->delete("s_quest");
//	testing ends

/*	([	TJ Quest
		"quest":	"探访垂笠老僧",
		"long":		"天机老人说：听闻最近有神秘组织频繁活动，你不妨去找城隍庙的和尚打听打听。",
		"short":	"去城隍庙找垂笠老僧打听神秘组织的情形",
		"owner":	"monk",		
		"location":	"城隍庙",		
		"duration":	1260,			
//		"cancel": 200,	// CC +200% 
		"difficulty":	400,			
		"exp_l":		6000,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),*/
	
/*	if (!query("open")) {
		tell_object(me,"垂笠老僧沉声道：此任务在调试中，暂时关闭。\n");
		return 1;
	}*/
		
	if (me->query("quest/quest")!= "探访垂笠老僧") {
		tell_object(me,"你站得片刻，垂笠老僧却是一言不发。\n");
		return 1;
	}
	
	if ( me->query("quest_time")+ me->query("quest/duration") < time()) {
		tell_object(me,"垂笠老僧皱眉道：你动作太慢，已经误了大事。\n");
		return 1;
	}
				
// 选择地区入口及地牢名字
		m = random(sizeof(area));
		arg = "/d/"+area[m] +"/";
		files= get_dir(arg);

		while(1)
		{
			i = random(sizeof(files));
			size = sizeof(files[i]);
//			message_vision("file is "+ files[i] +"\n", me);
			if(files[i][(size-2)..size]==".c")
			{
				room_name = arg + files[i];
				room = find_object(room_name);
				if (!room)
					room = load_object(room_name);
				if (!room)	continue;
				if (!room->query("short")) 		continue;
				if (room->query("no_fly")) 		continue;
				if (room->query("no_fight")) 	continue;	
				if (room->query("underwater")) 	continue;
				break;
			}
		}

// testing
//			room_name = "/d/wiz/demoroom.c";
//			room = find_object(room_name);
// testing ends
			
		orig_name = word1[random(sizeof(word1))];
		orig_name += word2[random(sizeof(word2))];
		orig_name += word3[random(sizeof(word3))];
		orig_name += word4[random(sizeof(word4))];
		orig_name += word5[random(sizeof(word5))];


//	选择Dungeon 种类

		chance = random(100);
		if (me->query_team())
			num = sizeof(me->query_team());
		else
			num = 1;
		
		// for soloer, it's either solo dungeon, or 2ppl dungeon.
		// for group, it's solo, 2ppl, or multiple NPC dungeons.
		
		if (num == 1) {				// soloer 80% single, 20% duo
			if (chance>=20)	nn=1;
			else	nn = 2;
		}
		if (num ==2 ) {				// duo 30% chance single, 65% chance duo, 5% chance triplex
			if (chance>=95)			nn=3;
			else if (chance>=60)	nn=1;
				else nn=2;
		}
		
		if (num >=3) {				// triplex 20% chance single, 70% chance duo, 30% chance triple
			if (chance>=80)	nn = 1;
			else if (chance> 30) nn =2;
				else 		nn = 3;
		}
						
		me->set("private_maze/destination", room_name);
		me->set("private_maze/orig_name", orig_name);
		me->set("private_maze/type", nn);		// 决定dungeon 的类别
		me->set("private_maze/difficulty",50);	// this is NPC's chance to perform
//		if (nn==3)	me->set("private_maze/difficulty",50);
		me->set("private_maze/create",1);		// a flag whether you create the maze yet
		me->set("private_maze/adjust",time());	// 由于是随机分布，如果实在找不到，我们允许每三分换一个地方看看
		
//		write ("nn = "+nn);	
		arg = "近日"HIR+orig_name+NOR CYN"非常猖狂，据说他们有一个据点设在"+c_area[m]+"的"WHT+room->query("short")+CYN"，你速去将其剿灭。"+ act[nn]+"。\n"NOR;
				
		// 必须将原来的Dungeon销毁, Using owner to search since sometimes the room/link is lost somehow
		dungeon_list = children("/obj/dungeon/standardmaze");
//		CHANNEL_D->do_sys_channel("sys",sprintf("%O\n", dungeon_list));
		mm = sizeof(dungeon_list);
		for (i=0;i<mm;i++){
			if (dungeon_list[i]->query_owner()== me->query("id")) {
				dungeon_list[i]->refresh_maze();
			}
		}
			
		tell_object(me, arg);
		
		if (me->query("marks/chuili_warning")<5) {
			tell_object(me, YEL"
垂笠老僧说：根据我的线索找到那个地方，使用entermaze命令便能进入，
具体可使用help entermaze察看。
由于还处在测试阶段，如果那个地方实在无法找到，每过三分钟可到我这
里换个地方（ask chuili seng about lost）如果对头实在太厉害，每过
五分钟也可到这里来换个地方（ask chuili seng about fail）\n"NOR);
			me->add("marks/chuili_warning",1);
		}
		
		
		// 改变天机Quest的说明		
		me->set("quest/quest","垂笠老僧的任务");
		me->set("quest/long","到"+c_area[m]+room->query("short")+ "去将匪窝剿灭");
		me->set("quest/location",c_area[m]+room->query("short"));
		me->set("quest/short",aa[nn]+"到"+c_area[m]+room->query("short")+ "去将匪窝剿灭");
		me->set("quest/duration",3600);
		me->set("quest/cancel",-1);
		me->set("quest_time",time());
		tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);

// 	testing
		if (wizardp(me)) {
			tell_object(me, sprintf("%O",me->query("private_maze")));
			tell_object(me, sprintf("%O",me->query("quest")));
		}
				
//	testing ends

		return 1;
	
//	return "生活可以优渥挥霍，也可以简朴平实。只要有梦、有理想，日子就可以过得舒适愉悦——从前他却怎么也参不透这一点。";

}


int change_area(){
	object me = this_player();
	string *area = ({ 	
		"huangshan", "huashan", "songshan", "palace", "laowu", 
		"resort", "qianfo", "qingping", "taoguan", "taoyuan", 
		"xinjiang","wanmei","eren",		
		"chuenyu", "taishan", "guanyin","wolfmount","qianjin",
		"biancheng", "zangbei","baiyun" ,"bat","changchun"});
	
	string *c_area =  ({"黄山","华山","嵩山","帝王谷","冰封小镇",
				"铁雪山庄","千佛山","清平山庄","三清山","桃源村",
				"新疆", "万梅山庄","恶人谷",
			    "黑松山","泰山","天枫山庄","狼山","千金楼", 
			    "边城", "藏北","白云岛","蝙蝠岛","长春岛",
			    });
	string arg, room_name, *files,orig_name;
	int i, n, m, nn, size, reward, exp, num, dur;
	object room, silver,room2;
		string	*act = ({ " ", "此事机密无比，你需单身前往", "该处甚为凶险，最好找个帮手","该处极为凶险，最好携三两帮手同行",});
	string	*aa  = ({ " ", "单身", "结伴", "聚三二人" });			    
	
	if (me->query("quest/quest")!= "垂笠老僧的任务") {
		tell_object(me, "垂笠老僧说：你来瞎搅和什么。\n");
		return 1;
	}
	
	if (!me->query("private_maze/create")) {
		tell_object(me,"垂笠老僧说：你不是已经找到了匪窝么？快快前去剿灭！\n");
		return 1;
	}
	
	if (me->query("quest_time")+ me->query("quest/duration")< time()) {
		tell_object(me,"太晚了，敌人已经闻风转移，这个任务失败了。\n");
		return 1;
	}

	dur = me->query("private_maze/adjust")+ 180 - time();
	if (dur > 0 ) {
		tell_object(me,"垂笠老僧不满地说：你是否仔细找过？再去找"+ dur+"秒钟吧。\n");
		return 1;
	}
		
	// 重新选择地区入口及地牢名字
		m = random(sizeof(area));
		arg = "/d/"+area[m] +"/";
		files= get_dir(arg);

		while(1)
		{
			i = random(sizeof(files));
			size = sizeof(files[i]);
//			message_vision("file is "+ files[i] +"\n", me);
			if(files[i][(size-2)..size]==".c")
			{
				room_name = arg + files[i];
				room = find_object(room_name);
				if (!room)
					room = load_object(room_name);
				if (!room)	continue;
				if (!room->query("short")) 		continue;
				if (room->query("no_fly")) 		continue;
				if (room->query("no_fight")) 	continue;	
				if (room->query("underwater")) 	continue;
				break;
			}
		}
		
		me->set("private_maze/destination", room_name);
		me->set("private_maze/adjust",time());
		
		nn = me->query("private_maze/type");
			
		// 改变天机Quest的说明		
		me->set("quest/long","到"+c_area[m]+room->query("short")+ "去将匪窝剿灭");
		me->set("quest/location",c_area[m]+room->query("short"));
		me->set("quest/short",aa[nn]+"到"+c_area[m]+room->query("short")+ "去将匪窝剿灭");
		me->set("quest/duration",3600);
		me->set("quest_time",time());
		
		arg = HIR+me->query("private_maze/orig_name")+NOR CYN"据说已把据点移到"+c_area[m]+"的"WHT+room->query("short")+CYN"，你速赶去将其剿灭。"+ act[nn]+"。\n"NOR;
		tell_object(me, arg);		
		tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);

// 	testing
		if (wizardp(me)) {
			tell_object(me, sprintf("%O",me->query("private_maze")));
			tell_object(me, sprintf("%O",me->query("quest")));
		}
				
//	testing ends
		
		return 1;
}

int change_maze(){
	object me=this_player();
	object *dungeon_list, room2;
	int i, mm,dur,killed;
	
	if (me->query("quest/quest")!= "垂笠老僧的任务") {
		tell_object(me, "垂笠老僧说：你来瞎搅和什么。\n");
		return 1;
	}
	
	if (me->query("private_maze/create")) {
		tell_object(me,"垂笠老僧说：我不是已经给你线索了么，怎么还不快去！\n");
		return 1;
	}
	
	if (me->query("quest_time")+ me->query("quest/duration")< time()) {
		tell_object(me,"太晚了，敌人已经闻风转移，这个任务失败了。\n");
		return 1;
	}

	dur = me->query("quest_time")+ 300 - time();
	if (dur > 0 ) {
		tell_object(me,"垂笠老僧沉吟片刻道：不去尝试，如何知道是否能行，再去试"+ dur+"秒钟吧。\n");
		return 1;
	}
	
		// 将原来的Dungeon销毁
			dungeon_list = children("/obj/dungeon/standardmaze");
//		CHANNEL_D->do_sys_channel("sys",sprintf("%O\n", dungeon_list));
			mm = sizeof(dungeon_list);
			for (i=0;i<mm;i++){
				if (dungeon_list[i]->query_owner()== me->query("id")) {
					if (dungeon_list[i]->has_player()) {
						tell_object(me,"垂笠老僧说：你的同伴还在那里，快快叫他们撤离吧。\n");
						return 1;
					}
//					CHANNEL_D->do_sys_channel("sys",sprintf("file is %s\n", file_name(dungeon_list[i])));					
					room2 = find_object("/obj/dungeon/standardmaze/" + me->query("id")+"/entry");
					if (room2) {
						if (room2->query("maze/cleared")) {
							tell_object(me,"垂笠老僧冷冷地说：想来骗我？门都没有！\n");
							return 1;
						}
						killed = room2->query("maze/npc_killed");
//						CHANNEL_D->do_sys_channel("sys", sprintf("killed is %d\n", killed));
					}										
					dungeon_list[i]->refresh_maze();
				}
			}

		tell_object(me,"垂笠老僧说，看来就算尝试，未必成功，不过，据说近期土匪防守有所松懈，你再去看看。\n");			
		
		me->set("private_maze/create",1);
		if (killed>=6)
			me->set("private_maze/carried_npc",killed);		// last failed one carried over, if it's failed, at least killed 6
		me->set("quest_time",time());
		tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
			
	// 	testing
		if (wizardp(me)) {
			tell_object(me, sprintf("%O",me->query("private_maze")));
			tell_object(me, sprintf("%O",me->query("quest")));
		}
				
//	testing ends
		
		return 1;
}

		