// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;

string getdam(object me, object obj);
string *skill_level_desc = ({
	BLU "初学乍练" NOR,
	HIB "粗通皮毛" NOR,
	HIB "半生不熟" NOR,
	HIB "马马虎虎" NOR,
	HIB "驾轻就熟" NOR,
	CYN "出类拔萃" NOR,
	CYN "神乎其技" NOR,
	CYN "出神入化" NOR,
	HIC "登峰造极" NOR,
	HIC "一代宗师" NOR,
	HIW "深不可测" NOR
});

string *knowledge_level_desc = ({
	BLU "新学乍用" NOR,
	HIB "初窥门径" NOR,
	HIB "略知一二" NOR,
	HIB "马马虎虎" NOR,
	HIB "已有小成" NOR,
	CYN "心领神会" NOR,
	CYN "了然於胸" NOR,
	CYN "豁然贯通" NOR,
	HIC "举世无双" NOR,
	HIC "震古铄今" NOR,
	HIW "深不可测" NOR
});
mapping area_name = ([ 
		"baiyun"	:	"白云城",
		"bat"		:	"蝙蝠岛",
		"bashan"	: 	"巴山",
		"bawang"	:	"饿虎岗",
		"biancheng"	:	"边城",
		"cave"		:   "风云地下城",
		"chenxiang"	:	"沉香镇",
		"chuenyu"	:	"黑松堡",
		"cyan"		: 	"明霞山",
		"daimiao"	:	"岱庙",
		"death"		:	"鬼门关",
		"eastcoast"	: 	"东海",
		"eren"		:    "恶人谷",
		"eren2"		:    "恶人谷",
		"fy"		:	"风云城",
		"fugui"		:    "富贵山庄",
		"fycycle"	:  	"风云外城",
		"fywall"	:   "风云城",
		"ghost"		:    "幽灵山庄",
		"guanwai"	:  	"关外",
		"guanyin"	:  	"天枫",
		"huangshan"	:	"黄山",
		"huashan"	:  	"华山",
		"jinan"		:    "济南",
		"laowu"		:    "老屋",
		"libie"		:    "无名小镇",
		"loulan"	:   "楼兰",
		"manglin"	:  	"莽林",
		"oldpine"	:  	"老松寨",
		"palace"	:   "帝王谷",
		"qianfo"	:   "千佛山",
		"qianjin"	:  	"千金楼",
		"qingping"	: 	"清平山庄",
		"quicksand"	:	"大沙漠",
		"resort"	:   "铁雪山庄",
		"shaolin"	:  	"少林寺",
		"shenshui"	: 	"神水宫",
		"songshan"	: 	"嵩山",
		"taiping"	:  	"太平镇",
		"taishan"	:  	"泰山",
		"taoguan"	:  	"桃源",
		"taoyuan"	:  	"三清观",
		"tieflag"	:  	"大旗谷",
		"wanmei"	:   "万梅山庄",
		"wolfmount"	:	"狼山",
		"wudang"	:   "武当",
		"xiangsi"	: 	"相思岭",
		"xinjiang"	: 	"新疆",
		"yingou"	:   "银钩赌坊",
		"zhaoze"	:	"沼泽地",
		"zangbei"	:	"藏北",
]);                             
string *heavy_level_desc= ({
	"极轻",
	"很轻",
	"不重",
	"不轻",
	"很重",
	"极重"	
});



string skill_level(string, int);
int main(object me, string arg)
{                               
	object ob, man, *all    ;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp, skill;             
	int i, cost;            
	object room;            
	string location,*area,line;
	mapping my;        
	                        
	                        
        seteuid(getuid());      
        skill=me->query_skill("begging",1);
        
                         
//	check requirement            
	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++) {
		if( living(all[i]) && !userp(all[i]) ) man = all[i];
	}                       
                                
        if (me->query("class")!="beggar")
		return notify_fail("只有丐帮弟子才能打探别人的消息！\n");
	
	if (skill<50)
		return notify_fail("你的乞讨之术不够高深（需高于50）\n");
	
	if ( !objectp(man) )    
		return notify_fail("周围没人能帮你去打探别人的消息！\n");

	if (arg==("monster nian"))
		return notify_fail("活动NPC无法打听。\n");

	if ( !arg )             
		return notify_fail("你要打听谁的消息？\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) 
		return notify_fail("你要打听谁的消息？\n");
	if ( wizardp(ob))
			return notify_fail("你要打听谁的消息？\n");
	if ( ob == me )         
		return notify_fail("请输入指令ｓｋｉｌｌｓ\n");
        if ( present(ob, environment(me)) )
                return notify_fail("你要打听的人就在这儿！\n");
	cost = me->query("max_gin")/(me->query_skill("begging",1)/10 + 1);
	if ( me->query("gin") <= cost )
		return notify_fail("现在你太累了，无法去打听别人的消息。\n");
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
		
//	start inquire
	tell_object(me, "你决定向" + man->name() + "打听关于" + ob->name() + "的消息。\n\n");
	message("vision", "只见" + me->name() + "交头接耳地跟" + man->name() + "说着话，好象在打听些什么。\n\n", 
		environment(me), ({ me, man }) );
	sp = me->query_skill("begging")*10 + me->query("kar")*5 + me->query("gin") + man->query("gin");
	dp = ob->query("kar")*10 + ob->query("gin")*3;
		me->receive_damage("gin", cost );
	if ( random(sp) < random(dp) || wizardp(ob))
		return notify_fail( man->name() + "摇了摇头，说道：这事我可不清楚，"
		 	+ RANK_D->query_respect(me) + "还是去向别人打听一下吧！\n");

	write(YEL"\n"+man->name()+YEL"悄悄地告诉你：\n\n"NOR);
//	basic information inquiry
	my = ob->query_entire_dbase();
	
	line = ob->query("title")?ob->query("title"):"";
	line += sprintf("    %s，%s，%s，%s岁，",
		ob->query("name"),
		(ob->query("national")? ob->query("national") : "本地生"),
		ob->query("gender"),
		chinese_number(ob->query("age")));
	
	if ( my["marry"] || my["divorced"]) {
        	if (my["marry"]) {
        		line += (ob->query("gender") == "女性" ? "嫁与":"娶妻")
        			+ my["marry_name"]+ "(" + my["marry"] +")。\n";  		
        	}
        	else
        		line += "现" + (ob->query("gender") == "女性" ? "寡居。":"鳏居。");
	}
	else
		line += "尚未婚配。";
		
	if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] )
                        line += sprintf("拜师%s。",
                                my["family"]["master_name"] );
        }
        
        if (userp(ob)) {
        if (my["PKS"]>80) line += "\n"+ob->name()+"凶狠极恶，嗜杀成性。";
        	else if (my["PKS"]>40) line+="\n"+ob->name()+"恃勇好斗，多伤人命。";
        	else if (my["PKS"]>10) line+="\n"+ob->name()+"偶有劣迹，却无恶行。";
        		else line += "\n"+ob->name()+"生性善良，宽厚容让。";
        } else line +="\n";
        	
	write (line);


//	skill inquiry	
	
	if (skill<100) 
		write ("打探不出此人的武功境界。\n");
	else {	
		skl = ob->query_skills();
		if(!sizeof(skl)) {
			write("此人出手"+getdam(me,ob)+"，什么都不会！\n");
		} else {
			write("此人出手"+getdam(me,ob)+"，所擅长的技能之一是：\n");
			sname  = sort_array( keys(skl), (: strcmp :) );
			map = ob->query_skill_map();
			if( mapp(map) ) mapped = values(map);
			if( !mapped ) mapped = ({});
			lrn = ob->query_learned();
			if( !mapp(lrn) ) lrn = ([]);
			i = random(sizeof(skl));
			printf("%s%s%-40s" NOR " - %-10s \n", 
				(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
				(member_array(sname[i], mapped)==-1? "  ": "□"),
				SKILL_D(sname[i])->name() + " (" + sname[i] + ")",
				skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			);
			write("\n");
		}
	}
	
//	location inquiry, for player, it's area only
	
	if (skill<150) 
		write("打探不出此人经常出没的地区。\n\n\n");
	else {
		room=environment(ob);
		area=keys(area_name);
		if (!room) 
			write("不清楚在哪里可以找到"+ob->name()+"。\n\n\n");
		else {
			location=domain_file(file_name(room));
			if (member_array(location,area)==-1)	
				write("不清楚在哪里可以找到"+ob->name()+"。\n\n\n");
			else if (skill<250)
				write(ob->name()+"好像最近经常在"+area_name[location]+"一带走动。\n\n\n");
			else 	
				write(ob->name()+"好像最近曾在"+area_name[location]+room->query("short")+"出现。\n\n\n");
		}	
	}
	me -> perform_busy(2);
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 20;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

string getdam(object me, object obj) {	
	int str, level, max_str, max_level;
	
	max_str = 120;
	max_level = sizeof(heavy_level_desc) - 1;
	
	str = obj->query_str();
	level = str * max_level / max_str;
	level = level > max_level ? max_level : level; 
	return heavy_level_desc[level];
}


int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	inquire <某人>[0m
[0;1;37m────────────────────────────────[0m   

这个指令可以让你打听别人的消息。此命令为丐帮弟子专用，
并需学习乞讨之术。技能等级越高，得到的信息就越多，可
以了解对方的身世，武功深浅，技能种类，甚至可以知晓对
方的大致位置。（至少需要５０级乞讨之术）

[0;1;37m────────────────────────────────[0m   

HELP
    );
    return 1;
}
