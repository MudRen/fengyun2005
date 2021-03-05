inherit ITEM;

void create()
{
    	set_name("易筋石" , ({ "powerstone" }) );
    	set_weight(600);
    	set("unit", "块");
    	set("long", "
这是一块载有绝世神功的易筋石。
命令: setski、setatt、setclass、setexp、fly
其中class的定义参看helpclass，
fly的定义参看helpfly
\n");
        set("no_get", 1);        
        set("value", 0);
        set("no_drop",1);
	::init_item();
}

void init()
{
        if (wizardp(this_player()))	{
	        add_action("setskillss", "setski");
	        add_action("setattss", "setatt");
		add_action("setdefaultss", "setdef");
		add_action("setclass", "setclass");
		add_action("setexp", "setexp");
		add_action("help_class","helpclass");
		add_action("goto_place","fly");
		add_action("help_place","helpfly");
		add_action("add_score","setscore");
	}
}


int add_score(string arg){
	int num;
	if (sscanf(arg,"%d",num)!= 1)
		return notify_fail("setexp 数字\n");;
	this_player()->add("score",num);
	tell_object(this_player(),"Your score has been added "+ (string)num + " .\n");
	return 1;
}

int setexp (string arg) {
	object me;
	int exp;
	me = this_player();
	if (sscanf(arg,"%d",exp)!= 1)
		return notify_fail("setexp 数字\n");;
	if (exp > 20000000) exp = 20000000;
	if (exp<0) exp = 0;
	me->set("combat_exp",exp);
	tell_object(me,"Your combat experience has been set to "+ (string)exp + " .\n");
	return 1;
}
	

int setskillss ( string arg)
{
	object me;
	string skilltype, skilllevel;
	int ski;
	me = this_player();		
        if(!arg) return notify_fail("Usage: setski skilltype skilllevel\n");
        if( sscanf(arg, "%s to %s", skilltype, skilllevel)==2
        || sscanf(arg, "%s %s", skilltype, skilllevel)==2 );
        else return notify_fail("Usage: setski skilltype skilllevel\n");
	ski = atoi(skilllevel);
	me->set_skill(skilltype , ski);
	tell_object(me, "Set your " + skilltype + " to " + skilllevel + "\n");
	return 1;
}
 
int setattss ( string arg)
{
        object me;
        string atttype, attlevel;
        int ski;
        me = this_player();
        if(!arg) return notify_fail("Usage: setatt atttype attlevel\n");
        if( sscanf(arg, "%s to %s", atttype, attlevel)==2
        || sscanf(arg, "%s %s", atttype, attlevel)==2 );
        else return notify_fail("Usage: setatt atttype attllevel\n");
        ski = atoi(attlevel);
        me->set(atttype , ski);
        tell_object(me, "Set your " + atttype + " to " + attlevel + "\n");
        return 1;
}


int setdefaultss( )
{
	object me;
	me = this_player();
	me->set("max_gin", 3000);
        me->set("max_kee", 99999);
        me->set("max_sen", 3000);
        me->set("eff_gin", 3000);
        me->set("eff_kee", 99999);
        me->set("eff_sen", 3000);
        me->set("gin", 3000);
        me->set("kee", 99999);
        me->set("sen", 3000);
        me->set("max_atman", 300);
        me->set("atman", 300);
        me->set("max_force", 300);
        me->set("force", 300);
        me->set("max_mana", 300);
        me->set("mana", 300);
	me->set("water", me->max_water_capacity());
        me->set("food", me->max_food_capacity());
	me->set("combat_exp", 1000);
	me->set_skill("unarmed", 30);
        me->set_skill("dodge", 30);
        me->set_skill("force", 30);
        me->set_skill("literate", 30);
        me->set_skill("parry", 30);
        me->set_skill("sword", 30);
        me->set_skill("blade", 30);
        me->set_skill("hammer", 30);
        tell_object(me, "DONE! \n");
	return 1;
}

int setclass ( string arg)
{
	object me;
	string classtype/*,user_class*/;
	me = this_player();	
	
        if(!arg) 
        	return notify_fail("Usage: setclass classtype\n");
        if( sscanf(arg, "%s", classtype)!=1)        
        	return notify_fail("Usage: setclass classtype\n");	
	me->set("class",classtype);
	tell_object(me, "Set your class to " + classtype + ".\n");
	return 1;
}


int query_autoload() { return 1; }


int help_class () {
		
	write("	
		assassin:	 金钱帮;
		bat:		 蝙蝠岛;
		ninja:	 	 忍者;
		legend:	 	 铁雪;
		huashan:	 华山;
		official:	 官府;
		beggar:	 	 丐帮;
		fugui:	 	富贵山庄;
		shaolin:	 少林;
		lama:		 大昭寺;
		wudang:		 武当;
		taoist:	 	 三清;
		bonze:	 	兴国禅寺;
		shenshui:	 神水宫;
		fighter:	 万梅山庄;
		demon:	 	 魔教;
		swordsman:	 神剑山庄;
		knight:	 	 快活林;
		yinshi:	 	 帝王谷;
		baiyun:	 	 白云;
		huangshan:	 黄山;
		wolfmount:	 狼山;	\n");
	return 1;
}

int help_place() {
	write (" you can fly to 
	fengyun/chenxiang/guanwai/changchun/
	bat/xinjiang/ghost/loulan/wanmei/xingguo\n");
	return 1;
}

int goto_place(string arg) {
	string location;
	object room, me/*, obj*/;
	me = this_player();
	
	
	switch (arg) {
		case "fengyun":		location = "/d/fy/fysquare";
					break;
		case "chenxiang":	location = "/d/chenxiang/cxcenter";
					break;
		case "guanwai":		location = "/d/guanwai/tower";
					break;		
		case "changchun":	location = "/d/changchun/island";
					break;
		case "bat":		location = "/d/bat/anbian";
					break;
		case "xinjiang":	location = "/d/xinjiang/bazha2";
					break;
		case "ghost":		location = "/d/ghost/forest9.c";
					break;
		case "loulan":		location = "/d/loulan/saintpalace";
					break;
		case "wanmei":		location = "/d/wanmei/playground";
					break;
		case "xingguo":		location = "/d/qianfo/yezhang";
					break;			
		default:		location = "/d/fy/fysquare";

	}
	
	location = resolve_path(me->query("cwd"), location);
	if( !sscanf(location, "%*s.c") ) location += ".c";
	
	seteuid(ROOT_UID);
	room = find_object(location);
	if (!room) {
		room = load_object(location);
	}
	me->move(location);
	seteuid(geteuid());
	return 1;
}
	
	