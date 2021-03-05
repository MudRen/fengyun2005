inherit __DIR__"tutor";

void create()
{
	set_name("惜双飞", ({ "demosword book","demosword" }));    
	set_weight(600);
	if( clonep() )
			set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("long",	"一本手抄的薄薄纸书，字迹凌乱不堪。\n你凝神看去，上面所记载的却是极深的武功。\n");
		set("no_drop", 1);
		set("no_get", 1);
		set("no_sell", 1);
		set("teaching", "demosword");
		set("teaching_limit", 150);
		//set("teaching_require", 100);
		set("value",10000);
		set("material", "paper");
 	}
}
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

