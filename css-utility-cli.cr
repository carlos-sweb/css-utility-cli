require "colorize"
require "option_parser"

#https://crystal-lang.org/reference/1.2/getting_started/cli.html

OptionParser.parse do |parser|
  parser.banner = "Welcome to Css-Utility"

  parser.on "-v", "--version", "Show version" do
    puts "version 1.0"
    exit
  end
  parser.on "-h", "--help", "Show help" do
    puts parser
    exit
  end
  parser.on "-c PROJECT", "--create=PROJECT", "create css-utility project" do | project |

    if !project
      puts "Existe es un String"
    else
      puts "No existe por favor necesito un valor"
    end
    # puts " Project : #{project.colorize(:green)} created"
    # puts " The Next step is run this command"
    # puts "  cd #{project} && css-utility init"


    exit
  end
  parser.on "-i", "--init", "initialize css-utility project" do
    puts "Project : aaaa created"
    puts "cd aaa && run css-utility init"
    exit
  end

end
