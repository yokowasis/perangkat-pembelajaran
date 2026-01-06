#!/bin/bash

# Perangkat Pembelajaran - Local Development Server
# Script untuk menjalankan Docsify CLI secara lokal

echo "🚀 Starting Perangkat Pembelajaran local server..."
echo "📍 Project: https://modul-belajar.code.app.web.id/"
echo ""

# Check if docsify-cli is installed
if ! command -v docsify &> /dev/null; then
    echo "❌ docsify-cli not found!"
    echo "📦 Installing docsify-cli globally..."
    npm install -g docsify-cli
    
    if [ $? -eq 0 ]; then
        echo "✅ docsify-cli installed successfully!"
    else
        echo "❌ Failed to install docsify-cli"
        echo "💡 Try running: sudo npm install -g docsify-cli"
        exit 1
    fi
fi

# Set default port
PORT=${1:-3000}

echo "🌐 Starting server on port $PORT..."
echo "📂 Serving from: $(pwd)"
echo ""
echo "🔗 Local server will be available at:"
echo "   http://localhost:$PORT"
echo ""
echo "📝 Press Ctrl+C to stop the server"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

# Start Docsify server
docsify serve . --port $PORT