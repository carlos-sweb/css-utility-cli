require "colorize"
require "file_utils"
require "option_parser"

# -> 694168

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

    if Dir.exists?(project)
      puts " The directory #{project.colorize(:green)} is already created"
    else
      Dir.mkdir( project )
      puts " Project : #{project.colorize(:green)} created !"
      puts " The Next step is run this command"
      puts "  cd #{project.colorize(:green)} && css-utility init"
    end
    exit
  end
  parser.on "-i", "--init", "initialize css-utility project" do

    puts "Project : aaaa created"
    puts "cd aaa && run css-utility init"
    exit
  end
  parser.invalid_option do |flag|
    STDERR.puts "Error: #{flag} is not a valid option."
    STDERR.puts ""
    STDERR.puts parser
    exit(1)
  end

end
