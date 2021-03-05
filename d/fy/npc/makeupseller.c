// 2009 FengYun
// Edit by hippo 2009.11
// 孝道 关联

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("芳儿", ({ "fang er","fang" }) );
	set("gender", "女性" );
	set("age", 29);
	set("title", HIY "千"+ HIR "面" + HIM "娘" + HIC"子"NOR);
	set("long",	"
这位年轻风骚的老板正对你狂抛媚眼儿。别看她娇滴滴的，却是五十年前
江湖闻名的千面观音铁如狐的孙女儿，家传的易容化装之术天下无双。\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/yanzhi":10,
                __DIR__"obj/bao":10,
                __DIR__"obj/huabag":10,
                __DIR__"obj/earth": 10,
		__DIR__"obj/pozhi":10,
		//__DIR__"obj/ikebana_stone": 0,
	]) );
	set_skill("unarmed",200);
	set_skill("dodge",200);
	setup();
	carry_object(__DIR__"obj/wch_skirt")->wear();
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
	switch( random(5) ) {
		case 0:
message_vision("$N笑着说道：这儿什么都有，买些回去给你的心上人吧。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N笑咪咪地说道：这位"+RANK_D->query_respect(ob)+
"要买什么？\n",this_object(),ob);
			break;
		case 2:
message_vision("$N用一种奇异的眼神望着$n。\n",this_object(),ob);
	}
}

int accept_object(object who, object ob)
{
	string tmpname;
//	string err;
	object newmask;
//	object rope,*obj;
//	int i;
	string gender, name, id;
	string newfile;
	object /**inv,*/ new_skull;
	
	if(ob->query("name")=="头颅骨" && ob->query("id")=="skull"
		&& !ob->query("recovered")){
 		if (REWARD_D->riddle_check(who,"古井疑云")!=2)
 		{
 			message_vision(CYN"
芳儿尖叫一声，差点没把头盖骨给摔了。
芳儿说：乖乖隆地东，你想把本姑娘吓死啊！\n"NOR, who);	
 			return 0;
 		}
		message_vision(CYN"
芳儿嗯地一声，犹犹豫豫地拿过头盖骨看了看。
芳儿叹了口气说：既然是知府大人的差事，我不接也不行。

芳儿咬了咬嘴唇：不过，要把这头骨还原，需要秦岭的粘土，这粘土唯有每年
进贡的西域商人才会送到，纵然是殷大人亲至，也不能白白就取了。\n"NOR, who);
		who->set("marks/give_skull",1); // extra steps... sorry can't fit in reward_d
		return 1;
 	}
 	
 	if (ob->query("name")==YEL"秦岭粘土"NOR && ob->query("skull_make")) 
 	{
 		if (!who->query("marks/give_skull"))
 		{
 			command("say 小店出门不退货，客官还请多多包涵。");
 			return 0;
 		}
 		who->delete("marks/give_skull");
 		message_vision(YEL"
芳儿对着$N表情僵硬的笑了笑，一声不响地接过粘土转入后房，
片刻后出来悄悄的塞给$N一样东西。\n"NOR, who);
		new_skull=new(AREA_TAOYUAN"obj/head_e");
		if (!new_skull->move(who))
			new_skull->move(environment());
		return 1;
	}
 			
 	
	tmpname = "/open/tempmask"+sprintf("%d",time());
	message_vision("$N对着$n表情僵硬的笑了笑．．．\n",this_object(),who);
	gender = (string)ob->query("targetgender");
	name = (string)ob->query("targetname");
	id = (string)ob->query("targetid");
	if( !stringp(id) ) return 0;
	if( !find_living(id)) return 0;
	if( !stringp(gender)) return 0;
	if( !stringp(name) ) return 0;
	if ((string)gender != "男性" && (string)gender != "女性")
		return 0;
	id = capitalize(id);
	newfile = read_file("/obj/item/orig_mask.o");
	if( !newfile) return 0;
	seteuid(ROOT_UID);
	newfile = replace_string( newfile, "男性", gender);
	newfile = replace_string( newfile, "maskman", id);
	newfile = replace_string( newfile, "蒙面人", name);
	if( !newfile) return 0;
	tmpname = tmpname + who->query("id") + ".c";

#ifdef	ENCRYPTED_WRITE	
	if( !write_file2(tmpname, newfile, 1))
		return 0;
#endif

#ifdef  NONENCRYPTED_WRITE	
	if( !write_file(tmpname, newfile, 1))
		return 0;
#endif

	newmask = new(tmpname);
	if (! rm( tmpname))
		{
		destruct(newmask);
		return 0;
		}
	if( !newmask) return 0;
	newmask->move(who);
	message_vision("$N悄悄的塞给$n一样东西。\n",this_object(), who);
        seteuid(getuid());
		return 1;
}

void reset()
{
	if (random(5)) {
		set("vendor_goods", ([
                __DIR__"obj/yanzhi":10,
                __DIR__"obj/bao":10,
                __DIR__"obj/huabag":10,
				__DIR__"obj/pozhi":10,
				__DIR__"obj/earth": 10,
				//__DIR__"obj/ikebana_stone": 0,
		]) );
	} else {
		set("vendor_goods", ([
                __DIR__"obj/yanzhi":10,
                __DIR__"obj/bao":10,
                __DIR__"obj/huabag":10,
				__DIR__"obj/pozhi":10,
				__DIR__"obj/earth": 10,
				__DIR__"obj/ikebana_stone": 1,
		]) );
		}
}
	
